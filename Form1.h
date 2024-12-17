/// <summary>
/// TP Animation de carre version C++.net visual Studio 2017
/// rev 2024
/// VERSION ELEVE a completer
/// </summary>

#pragma once

#include "carre.h"

namespace tpcarrewineleve {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 est une fenêtre avec un carré rouge
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			// instanciation dans le tas managé du carré numéro 1 
			nbcarre = 10;
			System::Random^ rand;
			tabCarre = gcnew array<CCarre^>(nbcarre);
			rand = gcnew Random();
			for (int i = 0; i < nbcarre; i++) {

				tabCarre[i] = gcnew CCarre;
				tabCarre[i]->Setsx(rand->Next(1100)); 
				tabCarre[i]->Setsy(rand->Next(100));
				tabCarre[i]->SetCote(rand->Next(80));

				switch (rand->Next(4))
				{
				case 0:
					tabCarre[i]->SetColor(Color::Blue);
					break;
				case 1:
					tabCarre[i]->SetColor(Color::Red);
					break;
				case 2:
					tabCarre[i]->SetColor(Color::Green);
					break;
				case 3:
					tabCarre[i]->SetColor(Color::Yellow);
					break;
				}
			}

			/*
			pcarre1 = gcnew CCarre();
			pcarre1->SetColor(Color::Red);

			pcarre1->Setsx(10);
			pcarre1->Setsy(10);
			pcarre1->SetCote(50);

			pcarre2 = gcnew CCarre();
			pcarre2->SetColor(Color::Blue);

			pcarre2->Setsx(70);
			pcarre2->Setsy(50);
			pcarre2->SetCote(50);*/

			this->timer1->Enabled = true;
			largeur = this->ClientRectangle.Width;
			hauteur = this->ClientRectangle.Height;
			choixCarre = 0;

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Le Carré numéro 1.
		/// </summary>
		//CCarre ^pcarre1;
		//CCarre^ pcarre2;
		array <CCarre^>^ tabCarre;
		/// <summary>
		/// Largeur de la fenêtre
		/// </summary>
		int largeur;
		/// <summary>
		/// Hauteur de la fenêtre
		/// </summary>
		int hauteur;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

		int nbcarre;
		int choixCarre;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 25;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1131, 524);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion

		/// <summary>
		/// Appelé périodiquement pour redessiner les carrés dans la fenetre
		/// </summary>
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		
		//pcarre1->Animer(this, largeur, hauteur);
		//pcarre2->Animer(this, largeur, hauteur);

		
		for (int i = 0; i < nbcarre; i++) {
			tabCarre[i]->Animer(this, largeur, hauteur);
		}
		

		largeur = this->ClientRectangle.Width;
		hauteur = this->ClientRectangle.Height;
		
				
		}
	private: System::Void Form1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// z 122; q 113; s 115; d 100
		
		choixCarre;
		int vitesse = 10;

		for (int j = 0; j < nbcarre; j++) {
			tabCarre[j]->Effacer(this);
		}
		
		switch (e->KeyChar)
		{
		case 'z':
			tabCarre[choixCarre]->Setsy(tabCarre[choixCarre]->Getsy() - vitesse);
			break;

		case 's':
			tabCarre[choixCarre]->Setsy(tabCarre[choixCarre]->Getsy() + vitesse);
			break;

		case 'q':
			tabCarre[choixCarre]->Setsx(tabCarre[choixCarre]->Getsx() - vitesse);
			break;

		case 'd':
			tabCarre[choixCarre]->Setsx(tabCarre[choixCarre]->Getsx() + vitesse);
			break;

		case 'e':
			if (choixCarre + 1 < nbcarre)
				choixCarre += 1;
			break;

		case 'a':
			if (choixCarre - 1 >= 0)
				choixCarre -= 1;
			break;
		}

		for (int j = 0; j < nbcarre; j++) {
			tabCarre[j]->Dessiner(this);
		}
		

	}
};
}

