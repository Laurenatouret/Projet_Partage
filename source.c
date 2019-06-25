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

/* Fonction de trace de cercle */
void cercle(float centreX, float centreY, float rayon)
{
	const int Pas = 50; // Nombre de secteurs pour tracer le cercle
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


void croixStart() {
	
		//exterieur croix verte 1
		couleurCourante(1, 215, 88);
		rectangle(315,100,475,500);
		couleurCourante(1, 215, 88);
		rectangle(200,215,600,375);
		
		//exterieur croix blanche 1
		couleurCourante(255, 255, 255);
		rectangle(325,110,465,490);
		couleurCourante(255, 255, 255);
		rectangle(210,225,590,365);
		
		//croix verte 2
		couleurCourante(1, 215, 88);
		rectangle(335,120,455,480);
		couleurCourante(1, 215, 88);
		rectangle(220,235,580,355);
		
		//croix blanche 2
		couleurCourante(255, 255, 255);
		rectangle(345,130,445,470);
		couleurCourante(255, 255, 255);
		rectangle(230,245,570,345);

		//croix VERTE 3
		couleurCourante(1, 215, 88);
		rectangle(355,140,435,460);
		couleurCourante(1, 215, 88);
		rectangle(240, 255, 560, 335);
		
		//ecriture start
		couleurCourante(255, 255, 255);
		epaisseurDeTrait(7);
		afficheChaine("START", 34, 345 , 280);
		

}


void connexion() {
	
	//bouton inscription
	couleurCourante(135, 233, 144);
	rectangle(190,200,390,400);
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(4);
	afficheChaine("INSCRIPTION", 20, 230 , 280);
	
	//bouton connexion
	couleurCourante(158, 253, 56);
	rectangle(410,200,610,400);
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(4);
	afficheChaine("CONNEXION", 20, 450 , 280);
	
	//bouton exit
	couleurCourante(4, 139,154);
	rectangle(0,0,150,50);
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(2);
	afficheChaine("EXIT", 20, 50 , 20);
}


void pointCouleur(structure *point) {
	
	float ab = rand()%640 + 60;
	float or =rand()%440 + 60;
	point -> x=ab;
	point -> y=or;
	
	if ( ab > 320 && or > 220 && ab < 480 && or < 380) {
		
	float ab = rand()%640 + 60;
	float or =rand()%440 + 60;
	point -> x=ab;
	point -> y=or;
	}
	

	

}

void affichageScore(){
	effaceFenetre(255,255,255);
	
	

	
	
	
	//bouton rejouer
	couleurCourante(4, 139, 154);
	rectangle(200,200,395,270);
	
	
	couleurCourante(255,255,255);
	rectangle(203,203,392,267);
	
	
	couleurCourante(4, 139, 154);
	rectangle(206,206,389,264);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(4);
	afficheChaine("REJOUER", 15, 255, 230);
	
	
	
	//bouton retour
	couleurCourante(135, 233, 144);
	rectangle(405,200,600,270);
	
	
	couleurCourante(255,255,255);
	rectangle(408,203,597,267);
	
	couleurCourante(135, 233, 144);
	rectangle(411,206,594,264);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(4);
	afficheChaine("RETOUR", 15, 470, 230);
	
	//bouton exit
	couleurCourante(4, 139,154);
	rectangle(0,0,150,50);
	couleurCourante(0, 0, 0);
	epaisseurDeTrait(2);
	afficheChaine("EXIT", 20, 50 , 20);
	
	
	
}

void curseur (int x1croix1,int y1croix1,int x2croix1,int y2croix1){
		//croix verte 1
		couleurCourante(1, 215, 88);
		rectangle(x1croix1,y1croix1,x2croix1,y2croix1);
		
		
		
}



int obstacle (coordBalles tab[30],int x1croix1,int y1croix1,int x2croix1,int y2croix1) {
	int i=0;
	int compteur =0,cpt=0;
	
	for(i=0;i<30;i++){
		
		//compteur pour acceder a la case d'apres, il compte les balles actives
		if (tab[i].b == 1) {
						compteur ++;
					}
					
				}
	for(i=0;i<compteur;i++) {
			if(tab[i].x <= x2croix1 && tab[i].x >= x1croix1 && tab[i].y<=y2croix1 && tab[i].y>=y1croix1) cpt++;	
				
	}
	
	//si une balle active touche le curseur, cpt prend la valeur 1
	if(cpt>1)cpt=1;
	return cpt;

	}
	
void initTab(coordBalles tab[30]){
	int i=0;
	
	for(i=0;i<30;i++) {
		tab[i].x = 0;
		tab[i].y = 0;
		tab[i].b = 0;
		tab[i].vx=7;
		tab[i].vy=-7;
	}
}
	
void afficheBalles(coordBalles tab[30]){
	int i=0;
	
	//on accede a chaque case du tableau et si la structure renvoie une case remplie par 1, il affiche une balle
	for(i=0;i<30;i++){
		if(tab[i].b==1) cercle(tab[i].x,tab[i].y,20);
	}
}	

void bougeBalles(coordBalles tab[30]){
	int i=0;
	
	//on accede encore a tt les cases du tableau
	for(i=0;i<30;i++){
		
		//on verifie que la balle est active (case du tableau = a 1)
		if(tab[i].b==1){
			
			//si la balle est positionnée dans la fenetre, elle se deplace normalement
			if(tab[i].x+2*tab[i].vx>0 && tab[i].x+2*tab[i].vx<LargeurFenetre) tab[i].x += tab[i].vx;
			
			//sinon elle atteint le bord et donc on la fait rebondir
			else{
				tab[i].vx=-tab[i].vx;
				tab[i].x += tab[i].vx;
			}
			
			//pareil pour les ordonnees
			if(tab[i].y+2*tab[i].vy>0 && tab[i].y+2*tab[i].vy<HauteurFenetre) tab[i].y += tab[i].vy;
			else{
				tab[i].vy=-tab[i].vy;
				tab[i].y+=tab[i].vy;
			}
		}
		
	}
}





  
