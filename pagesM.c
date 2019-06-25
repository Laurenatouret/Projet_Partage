#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../tpGfx/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../tpGfx/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../tpGfx/ESLib.h" // Pour utiliser valeurAleatoire()
#include "pagesH.h"

// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

// Fonction de trace de cercle
void cercle(float centreX, float centreY, float rayon);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	
	return 0;
}



/* Fonction de trace de cercle */
void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 20; // Nombre de secteurs pour tracer le cercle
	const double PasAngulaire = 2.*M_PI/Pas;
	int index;
	
	for (index = 0; index < Pas; ++index) // Pour chaque secteur
	{
		const double angle = 2.*M_PI*index/Pas; // on calcule l'angle de depart du secteur
		triangle(centreX, centreY,
				 centreX+rayon*cos(angle), centreY+rayon*sin(angle),
				 centreX+rayon*cos(angle+PasAngulaire), centreY+rayon*sin(angle+PasAngulaire));
			// On trace le secteur a l'aide d'un triangle => approximation d'un cercle
	}
	
}


/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB* memoire= NULL;
	static DonneesImageRGB* mouvement= NULL;
	static DonneesImageRGB* rapidite= NULL;
	static DonneesImageRGB* image = NULL;
	
	static test c;
	/*Elsa 
	static structure point;
	static int resultat = 0;
	int temps = 0;
	int tempsFinal = 0;
	long sec = CLOCKS_PER_SEC;

	*/


	switch (evenement)
	{
		case Initialisation:
		memoire = lisBMPRGB ("../memoire.bmp");
		mouvement= lisBMPRGB("../mouvement.bmp");
		rapidite = lisBMPRGB("../rapidite.bmp");
		image = lisBMPRGB ("../flying.bmp");
		/*
			point.x = 300;
			point.y = 300;
			couleurCourante(255, 0, 0);
			cercle(300, 300, 30);
			clock_t ti, tf;
			ti = clock();
			
			temps = (ti/sec);
			printf("le temps : %i    ",temps);
		*/


			demandeTemporisation(20);
			break;
		
		case Temporisation:
			gereClic(c,image,memoire,mouvement,rapidite);

			rafraichisFenetre();
			break;
			
		case Affichage:					
			effaceFenetre (255, 255, 255);
			pagetest();
			gereClic(c,image,memoire,mouvement,rapidite);
			/*Elsa*/
			/*
			effaceFenetre(255,255,255);
			couleurCourante(255, 0, 0);
			cercle(point.x,point.y, 30);
			rafraichisFenetre();
			
			
			tf = clock();
			tempsFinal = (tf/sec);
			 
			if (tempsFinal > 11) {
				
				effaceFenetre(255,255,255);
				affichageScore();
				printf("le score est de %d    ", resultat);
				printf("le temps final est de %d      ", tempsFinal);
				
				
			}
			*/					
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					
					termineBoucleEvenements();
					break;

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
		
			if (etatBoutonSouris() == GaucheAppuye)
			{
				c= gereClic1(c);
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran

			printf("Largeur : %d\t", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}
