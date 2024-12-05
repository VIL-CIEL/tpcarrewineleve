/// <summary>
/// TP Animation de carre version C++.net visual Studio 2017
/// rev 2024
/// VERSION ELEVE a completer
/// </summary>

using namespace System;
using namespace System::Drawing;

/// <summary>
/// Carr� de couleur
/// </summary>
ref class CCarre
	{
		private :
			
			int cote;
			int sx;
			int sy;
			Color color;
		
		public :
			CCarre()
			{
				sx = 10;
				sy = 10;
				cote = 20;
				color = Color::Red;
			}

			/// <summary>
			/// initialise m_x priv�
			/// </summary>
			/// <param name="x">Position x du carr�</param>
			void Setsx(int x1)
			{
				// A COMPLETER ///////////////////////////////////////////////////////////////////////////
			}

			/// <summary>
			/// retourne m_x priv�
			/// </summary>
			/// <returns>Position x du carr�</returns>
			int Getsx()
			{
				// A COMPLETER ///////////////////////////////////////////////////////////////////////
				return 0; // a modifier
			}

			/// <summary>
			/// initialise m_y priv�
			/// </summary>
			/// <param name="y">Position y du carr�</param>
			void Setsy(int y1)
			{
				// A COMPLETER //////////////////////////////////////////////////////////////////////////
				
			}

			/// <summary>
			/// retourne m_y priv�
			/// </summary>
			/// <returns>Position y du carr�</returns>
			int Getsy()
			{
				// A COMPLETER //////////////////////////////////////////////////////////////////////
				return 0; // a modifier
			}


			/// <summary>
			/// initialise m_color priv�
			/// </summary>
			/// <param name="couleur">Couleur du carr�</param>
			void SetColor(Color couleur) 
			{
				color=couleur;
			}

			/// <summary>
			/// initialise m_cote priv�
			/// </summary>
			/// <param name="cote">Cot� du carr�</param>
			void SetCote(int cote)
			{
				// A COMPLETER /////////////////////////////////////////////////////////////////////////
			}

			/// <summary>
			/// retourne m_cote priv�
			/// </summary>
			/// <returns>Cot� du carr�</returns>
			int GetCote() 
			{
				// A COMPLETER ////////////////////////////////////////////////////////////////////////
				return 0; // a modifier
			}

			/// <summary>
			/// D�place le carr� suivant un vecteur d�placelent dx et dy
			/// </summary>
			/// <param name="dx">Valeur dx du d�placement</param>
			/// <param name="dy">Valeur dy du d�placement</param>
			void Deplacer(int dx, int dy) 
			{
				// A COMPLETER /////////////////////////////////////////////////////////////////////
			}

			/// <summary>
			/// Dessine le carr� 
			/// </summary>
			/// <param name="form">pointeur sur la fen�tre dans laquelle on dessine.</param>
			void Dessiner(System::Windows::Forms::Form ^form)
			{
				Graphics ^g = form->CreateGraphics();
				g->FillRectangle(gcnew SolidBrush(color), sx,sy, cote, cote);
			}

			/// <summary>
			/// Efface le carr� 
			/// </summary>
			/// <param name="form">pointeur sur la fen�tre dans laquelle on dessine.</param>
			void Effacer(System::Windows::Forms::Form ^form)
			{
				Graphics ^g = form->CreateGraphics();
				g->FillRectangle(gcnew SolidBrush(form->BackColor), sx, sy, cote, cote);
			}
				
	};