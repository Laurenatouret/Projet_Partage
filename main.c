#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "projet.h"



// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

//void pageJeuMemoire(DonneesImageRGB* image);
//void pageJeuMobilite(DonneesImageRGB* image);
//void pageJeuTestVA(DonneesImageRGB* image);
void snakeN1(void);
void pointN1(int px1,int py1);
int etatPoint1(int px1,int py1,int erreur);
void snakeN2(void);
void pointN2(int px2,int py2);
void snakeN3(void);
void pointN3(int px3,int py3);
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
	static int page;
	static int px1;
	static int py1;	
	static int px2;
	static int py2;
	static int px3;
	static int py3;
	static int dedans;
	static int erreur;
	static int faute1;
	static int faute2;
	static int faute3;
	static int faute;
	static char f1[20];
	static char f2[20];
	static char f3[20];
	static char fT[20];
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	switch (evenement)
	{
		case Initialisation:
			image = lisBMPRGB("flying.bmp");
			px1=400;
			py1=580;
			px2=730;
			py2=555;
			px3=25;
			py3=545;
			page=1;
			faute=0;
			faute1=0;
			faute2=0;
			faute3=0;
			demandeTemporisation(20);
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:
			// On part d'un fond d'ecran blanc
			effaceFenetre (255, 255, 255);
			//pageJeuMemoire(image);
			//pageJeuMobilite(image);
			//pageJeuTestVA(image);
			if(page==1){
				snakeN1();
				pointN1(px1,py1);
				dedans = etatPoint1(px1,py1,dedans);
				if(tempsErreur(dedans, erreur) != erreur){
					erreur = tempsErreur(dedans, erreur);
				}else if(erreur != 0){
					erreur = 0;
					faute1 += 1;
				}
				printf("erreur=%d\n",faute1);
				sprintf(f1,"%d fautes",faute1);
			}else if(page==2){
				effaceFenetre (255, 255, 255);
				snakeN2();
				pointN2(px2,py2);
				dedans = etatPoint2(px2,py2,dedans);
				if(tempsErreur(dedans, erreur) != erreur){
					erreur = tempsErreur(dedans, erreur);
				}else if(erreur != 0){
					erreur = 0;
					faute2 += 1;
				}
				printf("erreur=%d\n",faute2);
				sprintf(f2,"%d fautes",faute2);
			}
			else if(page==3){
				effaceFenetre (255, 255, 255);
				snakeN3();
				pointN3(px3,py3);
				dedans = etatPoint3(px3,py3,dedans);
				if(tempsErreur(dedans, erreur) != erreur){
					erreur = tempsErreur(dedans, erreur);
				}else if(erreur != 0){
					erreur = 0;
					faute3 += 1;
				}
				printf("erreur=%d\n",faute3);
				sprintf(f3,"%d fautes",faute3);
			}
			else if(page==4){
				effaceFenetre(255,255,255);
				faute=faute1+faute2+faute3;
				sprintf(fT,"TOTAL : %d fautes",faute);
				pageResultat();
				couleurCourante(0,0,0);
				epaisseurDeTrait(2);
				afficheChaine(f1,25,LargeurFenetre-600,HauteurFenetre-285);
				afficheChaine(f2,25,LargeurFenetre-600,HauteurFenetre-365);
				afficheChaine(f3,25,LargeurFenetre-600,HauteurFenetre-445);
				afficheChaine(fT,25,LargeurFenetre-362,HauteurFenetre-388);
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
				printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			else if (etatBoutonSouris() == GaucheRelache)
			{
				if(px1>LargeurFenetre-145 && py1>HauteurFenetre-525 && px1<LargeurFenetre-50 && py1<HauteurFenetre-450 && page == 1){
					page=2;
				}
				if(px2>LargeurFenetre-120 && py2>HauteurFenetre-585 && px2<LargeurFenetre-50 && py2<HauteurFenetre-560 && page == 2){
					page=3;
				}
				if(px3>LargeurFenetre-210 && py3>HauteurFenetre-575 && px3<LargeurFenetre-145 && py3<HauteurFenetre-555 && page == 3){
					page=4;
				}
				printf("Bouton gauche relache en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());
			}
			break;
		
		case Souris: // Si la souris est deplacee
			if(page == 1){
				px1=abscisseSouris();
				py1=ordonneeSouris();
				printf("%d,%d\n",px1,py1);
			}else if(page==2){
				px2=abscisseSouris();
				py2=ordonneeSouris();
				printf("%d,%d\n",px2,py2);
			}else if(page == 3){
				px3=abscisseSouris();
				py3=ordonneeSouris();
				printf("%d,%d\n",px3,py3);
			}
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			break;
	}
}

