#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../ESLib.h" // Pour utiliser valeurAleatoire()
#include "header.h"
#include <time.h>


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600

// Fonction de trace de cercle

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);



int main(int argc, char **argv)
{
	srand(time(0));
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */
	lanceBoucleEvenements();
	
	return 0;
}






/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas
	static DonneesImageRGB *image = NULL; // L'image a afficher au centre de l'ecran
	
	
	//static int clic1;
	//static int clic2;
	static int var = 0;
	static float tempsF = 0;
	static int temps = 15	;
	static char score[50];
	static int bFin = 0;
	static char tps[50];
	
	static structure point;
	static int resultat = 0;
	
	
	
	
	//balle
	/*int var =0;
	static float tempsf = 0;
	static int temps=0;
	static int bFin =0;
	static char tps [50] ;
	
	
	
	
	// balle 1
	
	
	
	static coordBalles tab[30];
	int compteur =0;
	int i=0;
	
	
	
	//  croix 
	static int x1croix1;
	static int y1croix1;
	static int x2croix1;
	static int y2croix1;*/




	switch (evenement){
		case Initialisation:
		
		
		
		
		
		// balle 1
		/*initTab(tab);
		tab[0].x=largeurFenetre()*valeurAleatoire();
		tab[0].y=hauteurFenetre()*valeurAleatoire();
		tab[0].b=1;
		tab[0].vx=7;
		tab[0].vy=-7;
		
		
		
				
			
		
		
		
		
		// croix
		x1croix1 = 300;
		y1croix1 = 300;
		x2croix1 = 330;
		y2croix1 = 370;
		couleurCourante(1, 215, 88);
		rectangle(300,300,330,370);*/
		
		
		
	
		
		
		
			point.x = 300;
			point.y = 300;
			couleurCourante(255, 0, 0);
			cercle(300, 300, 30);
			
			
			

			
			
			

		
			demandeTemporisation(20);
			break;
		
		case Temporisation:
		
		if (bFin == 0 ) var ++;
		tempsF = var*20/1000;
		temps = tempsF;
		
		
		
		if (temps<15) bFin = 0;
		else bFin = 1 ;
		
		
		
			/*if(bFin==0)var++;
			
			//la temporisation est en milisecs donc on la convertis en secondes
			tempsf=var*20/1000;
			
			//on convertis le flottant en entier pour pas afficher un nombre avec plien de virgules
			temps=tempsf;
			
			// On met a jour les coordonnees de la balle 1
			
			
			
			
			// on me a jour les coordonnées de la croix
			if(abscisseSouris() - 15 > 0 && abscisseSouris() + 15 < LargeurFenetre && ordonneeSouris () -35 > 0 && ordonneeSouris () + 35 < HauteurFenetre) {
			x1croix1 = abscisseSouris() - 15;
			x2croix1 = abscisseSouris() + 15;
			y1croix1 = ordonneeSouris() - 35;
			y2croix1 = ordonneeSouris() + 35;
			
		}
			
			curseur(x1croix1, y1croix1, x2croix1, y2croix1);
			
			
			// On fait rebondir la balle 1 si necessaire
			bougeBalles(tab);
				
				//faire apparaitre les balles
			if (temps%5 == 1 && tab[29].b == 0 && var%50==0) {
				printf("%d\n",temps);
				for(i=0;i<30;i++) {
					if (tab[i].b == 1) {
						compteur ++;
					}
					
				}
				
				//on rempli la case du tableau pour detecter qu'il faut en creer une nouvelle
				tab[compteur].b = 1;
				
				//on lui donnne une position aleatoire
				tab[compteur].x=valeurAleatoire()*largeurFenetre();
				tab[compteur].y=valeurAleatoire()*hauteurFenetre();
			}*/
			

			rafraichisFenetre();
			
			//demandeTemporisation(20);
			
				
			break;
			
		case Affichage:
		
		
		
		
			
			// si elle touche un obstacle, la fonction (cpt) sera = a 1, on prend une nouvelle variable  bfin=1 donc le jeu se termine 
			/*if(obstacle(tab,x1croix1,y1croix1,x2croix1,y2croix1)==1) bFin=1;
			
			if(bFin == 0) {
				
				effaceFenetre(255,255,255);
				// Affichage du curseur a deplacer 
				curseur( x1croix1, y1croix1, x2croix1, y2croix1);
			
				// Affichage de la balle 1
				couleurCourante(255,20,20);
				afficheBalles(tab);
			
			
			}
			
			
		
		else if (bFin == 1) {
			
			
				
				effaceFenetre(255,255,255);
				affichageScore();
				
				
				//bouton score 
				couleurCourante(0,0,0);
				epaisseurDeTrait(4);
				sprintf(tps, " vous avez tenu %d secondes",temps);
				afficheChaine(tps,30, 100,400);
				
				
				
		}
		
		else ; */
			

			//printf("%d",bFin); 
			
			
			
			
			
			
			if (bFin == 0) {
				effaceFenetre(255,255,255);
				couleurCourante(255, 0, 0);
				cercle(point.x,point.y, 30);
				
				//rectange ext
				couleurCourante(4, 139,154);
				rectangle(350,250,450,350);
				
				//rectange blanc
				couleurCourante(255, 255,255);
				rectangle(354,254,446,346);
				
				//rectange int
				couleurCourante(4, 139,154);
				rectangle(358,258,442,342);
				
				//affichage du temps
				couleurCourante(255,255,255);
				epaisseurDeTrait(4);
				sprintf(tps, " %d",temps);
				afficheChaine(tps,28,360,285);
				rafraichisFenetre();
				
				
			}
				
				
				
			
			
			else {
				system("clear");
		
				effaceFenetre(255,255,255);
				affichageScore(); 
				couleurCourante(0,0,0);
				epaisseurDeTrait(4);
				sprintf(score, " vous avez touche %d points en 15 secondes",resultat);
				afficheChaine(score,25, 50,400);
				
				
			}
			
			
			
			
			
			


			
				
			
	
				
		
			//croix verte
			//croixStart();
			
			//if (clic1 == 1) {
				
			//PAGE INSCRIPTION
			//effaceFenetre (255, 255, 255);
			//connexion();
				//if (clic2 == 1) {
					//termineBoucleEvenements();
				//}
				//else{};
				
				
			
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
				
				
				//int a =(point.x)-30;
				
				
				if( (abscisseSouris() >= (point.x) -30) && (abscisseSouris() <= (point.x)+30) && (ordonneeSouris() >= (point.y)-30)  && (ordonneeSouris() <= (point.y)+30)) {
				pointCouleur(&point);
				resultat ++;
				
				}
				
				//relancer une partie points
				if(bFin==1){
					if (abscisseSouris()>=206 && abscisseSouris()<=389 && ordonneeSouris()>=206 && ordonneeSouris()<=264){
						
						
						bFin = 0;
						temps=0;
						resultat = 0;
						var = 0;
						point.x = 300;
						point.y = 300;
						couleurCourante(255, 0, 0);
						cercle(300, 300, 30);
					}					
				}
				
				//relancer une partie  balle
				/*if(bFin==1){
					if(abscisseSouris()>=206 && abscisseSouris()<=389 && ordonneeSouris()>=206 && ordonneeSouris()<=264){
						bFin=0;
						initTab(tab);
						tab[0].x=largeurFenetre()*valeurAleatoire();
						tab[0].y=hauteurFenetre()*valeurAleatoire();
						tab[0].b=1;
						tab[0].vx=7;
						tab[0].vy=-7;
						var=0;
						x1croix1=0;
						y1croix1 =0;
						x2croix1 =0;
						y2croix1 =0;
						
						
					}
					
				} */
				
				
				
				/*if(abscisseSouris() >=315 && abscisseSouris() <= 475 && ordonneeSouris() >= 100  && ordonneeSouris() <= 500) {
					clic1 = 1;
				}
					
				else if(abscisseSouris() >=200 && abscisseSouris() <= 600 && ordonneeSouris() >= 215  && ordonneeSouris() <= 375) {
						clic1=1;
				
				}
				
				
				else if(abscisseSouris() >=0 && abscisseSouris() <= 150 && ordonneeSouris() >= 0  && ordonneeSouris() <= 50) {
						clic2=1;
				
				}  */
				
				
				
				
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
			// Donc le systeme nous en informe
			break;
			
	}
}






