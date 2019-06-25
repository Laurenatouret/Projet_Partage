#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include <time.h>
#include "couleur.h"


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

void page(void);
void afficheTab(char tabCouleur[20][6]);
int aleatoire(int max, int min);
couleur afficheCouleur(couleur c);
verif verifCouleurRectangle1(couleur c,int rectangle, verif V, int aleaC);
verif verifCouleurRectangle2(couleur c,int rectangle, verif V, int aleaC);
verif verifCouleurRectangle3(couleur c,int rectangle, verif V, int aleaC);
void pageResultat(void);
/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	//cette ligne prépare simplement une fenêtre graphique de nom et de taille données
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	// lancer la boucle de gestion des évènements
	
	return 0;
}


/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	static char tabCouleur[20][6];
	static int aleaC;
	static int aleaM;
	static int rectangle;
	static verif V;
	static couleur c;
	static chrono k;
	static char K[50];
	static int Page = 0;
	static char p[20];
	static char f[20];
	switch (evenement)
	{
		case Initialisation:
			afficheTab(tabCouleur);
			c = afficheCouleur(c);
			k.min = 0;
			k.sec = 0;
			demandeTemporisation(1500);
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
				// On part d'un fond d'ecran blanc
				effaceFenetre (255, 255, 255);
				if (Page == 0)
				{
					page();
				aleaC=aleatoire(19,0);
				couleurCourante(c.tabC[aleaC][0],c.tabC[aleaC][1],c.tabC[aleaC][2]);
				epaisseurDeTrait(3);
				aleaM=aleatoire(19,0);
				afficheChaine(tabCouleur[aleaM],100,LargeurFenetre-550,HauteurFenetre-300);
				k = majChrono(k, &Page);
				sprintf(K,"chrono: %d secs",k.sec);
				couleurCourante(243, 214, 23);
				epaisseurDeTrait(2);
				afficheChaine(K,15,LargeurFenetre-795,HauteurFenetre-130);
				}
				if(Page==1){
					pageResultat();
					sprintf(p,"%d",V.point);
					sprintf(f,"%d",V.faute);
					afficheChaine(p,25,LargeurFenetre-600,HauteurFenetre-285);
					afficheChaine(f,25,LargeurFenetre-600,HauteurFenetre-365);
				}
			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					libereDonneesImageRGB(&image); /* On libere la structure image,
					c'est plus propre, meme si on va sortir du programme juste apres */
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
				if(abscisseSouris()>LargeurFenetre-700 && ordonneeSouris()>HauteurFenetre-550 && abscisseSouris()<LargeurFenetre-550 && ordonneeSouris()<HauteurFenetre-400){
					V=verifCouleurRectangle1(c,rectangle,V, aleaC);
					printf("%d\n", aleaC);
				}
				else if(abscisseSouris()>LargeurFenetre-500 && ordonneeSouris()>HauteurFenetre-550 && abscisseSouris()<LargeurFenetre-350 && ordonneeSouris()<HauteurFenetre-400){
					V=verifCouleurRectangle2(c,rectangle,V,aleaC);
				}
				else if(abscisseSouris()>LargeurFenetre-300 && ordonneeSouris()>HauteurFenetre-550 && abscisseSouris()<LargeurFenetre-150 && ordonneeSouris()<HauteurFenetre-400){
					V=verifCouleurRectangle3(c,rectangle,V,aleaC);
				}
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
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
			break;
	}
}

