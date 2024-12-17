/// @file NomDuFichier.h 
/// @brief Programme principal du TP� 
/// @details Ce programme utilise � 
/// @author Serge Delbosc 
/// @version 0.1 - Visual Studio 2019 
/// @date 09/09/2024 
/// <summary>
/// TP Animation de carre version C++.net visual Studio 2017
/// rev 2024
/// VERSION ELEVE a completer
/// </summary>
/// 
using namespace System;
using namespace System::Drawing;

/// <summary>
/// Carr� de couleur
/// </summary>
ref class CCarre
	{
		private :
			/// @brief la longueur du cot� du carr�
			int cote;
			/// @brief la coordonn�es x du carr�
			int sx;
			/// @brief la coordonn�es y du carr�
			int sy;
			/// @brief la couleur du carr� 
			Color color;
			/// @brief variable de compteur pour l'animation
			int dx;
		
		public :
			CCarre()
			{
				sx = 10;
				sy = 10;
				cote = 20;
				color = Color::Red;
				dx = 1;
			}

			/// <summary>
			/// initialise m_x priv�
			/// </summary>
			/// <param name="x">Position x du carr�</param>
			void Setsx(int x1)
			{
				sx = x1;
			}

			/// <summary>
			/// retourne m_x priv�
			/// </summary>
			/// <returns>Position x du carr�</returns>
			int Getsx()
			{
				return sx;
			}

			/// <summary>
			/// initialise m_y priv�
			/// </summary>
			/// <param name="y">Position y du carr�</param>
			void Setsy(int y1)
			{
				sy = y1;
				
			}

			/// <summary>
			/// retourne m_y priv�
			/// </summary>
			/// <returns>Position y du carr�</returns>
			int Getsy()
			{
				return sy;
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
			void SetCote(int cote1)
			{
				cote = cote1;
			}

			/// <summary>
			/// retourne m_cote priv�
			/// </summary>
			/// <returns>Cot� du carr�</returns>
			int GetCote() 
			{
				return cote;
			}

			/// <summary>
			/// D�place le carr� suivant un vecteur d�placelent dx et dy
			/// </summary>
			/// <param name="dx">Valeur dx du d�placement</param>
			/// <param name="dy">Valeur dy du d�placement</param>
			void Deplacer(int dx, int dy) 
			{
				sx += dx;
				sy += dy;

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
			
			/// <summary>
			/// Anime le carr�
			/// </summary>
			/// <param name="form"></param>
			/// @brief Fonction d'animation
			/// @param[in] Form Carre
			/// @param[in] largeur largeur de la fenetre
			/// @param[in] hauteur hauteur de la fenetre
			/// @param[out] void
			/// @return void
			void Animer(System::Windows::Forms::Form^ form, int largeur, int hauteur) {
				
				if (dx <= 0) {
					if (sy + cote < hauteur) {
						Effacer(form);
						Deplacer(0, cote*1.5);
						Dessiner(form);
					}
					if (sy + cote >= hauteur) {
						dx = 10;
					}
				}
				else {
					Effacer(form);
					Deplacer(0, -(cote*1.4) );
					Dessiner(form);
					dx -= 1;
				}
					
			}
	};