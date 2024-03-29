#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include "../../tpGfx/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../../tpGfx/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../../tpGfx/ESLib.h" // Pour utiliser valeurAleatoire()
#include "mem.h"


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
	static DonneesImageRGB* dos = NULL;
	
	srand(time(0));
	static carte initTab[3][4];
	static carte tabMel[3][4];
	static int cpt=0;
	static int x=0;
	static int y=0;
	static int dosH=0;
	static int dosL=0;
	
	carte c;


	switch (evenement)
	{
		case Initialisation:			
			dos = lisBMPRGB("../../dos.bmp");
	
			printf("1\n");
			initCarte(c);
			iniTab(initTab,c);
			iniMel(tabMel,c);
			iniEtat(dos, c, tabMel);
			printf("mel ok\n");
			printf("placement lancement\n");
			placement(c, tabMel, initTab);
			printf("placement ok\n");
			mel(initTab, tabMel,c);

			
			

			demandeTemporisation(20);
			break;
		
		case Temporisation:
			if(cpt==2){
				condition(tabMel, c);
				printfTab(tabMel);
				c = nettoie(tabMel, c);
				final(tabMel, c);
				printfTab(tabMel);
				cpt = 0;
			}
				
			rafraichisFenetre();
			break;
			
		case Affichage:
			
			effaceFenetre (255, 255, 255);	
			afficheDos(dos, c, tabMel);	
			//printf("affiche lancement\n");
			afficheImage(c,tabMel);
			//printf("lancement ok\n");
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
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
		dosL = dos->largeurImage;
		dosH = dos->hauteurImage;
		x = abscisseSouris();
		y = ordonneeSouris();
			if (etatBoutonSouris() == GaucheAppuye)
			{
				if(
		(75<x && x<75+dosL && 55<y && y<55+dosH)
	||(250<x && x<250 + dosL && 55<y && y<55+dosH)
	||(425<x && x<425+dosL && 55<y && y<55+dosH)
	||(600<x && x<600+dosL && 55<y && y<55+dosH)
	||(75<x && x<75+dosL && 230<y && y<230+dosH)
	||(250<x && x<250+dosL && 230<y && y<230+dosH)
	||(425<x && x<475+dosL && 230<y && y<230+dosH)
	||(600<x && x<600+dosL && 230<y && y<230+dosH)
	||(75<x && x<75+dosL && 405<y && y<405+dosH)
	||(250<x && x<250+dosL && 405<y && y<405+dosH)
	||(425<x && x<425+dosL && 405<y && y<405+dosH)
	||(600<x && x<600+dosL && 405<y && y<405+dosH)){
		
				Etat(dos,tabMel,c);
				cpt++;
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			
				}}
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




	
