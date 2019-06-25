#include "pagesH.h"

void gereClic(test c, DonneesImageRGB* image,DonneesImageRGB* memoire,DonneesImageRGB* mouvement,DonneesImageRGB* rapidite) {
	switch(c.clic1) {
		case 1:
		effaceFenetre (255, 255, 255);	
		choixTest(memoire,mouvement,rapidite);
		break;
		
		case 2:
		effaceFenetre(255,255,255);
		pageJeuMemoire(image);
		break;
		
		case 3:
		effaceFenetre(255,255,255);
		pageJeuMobilite( image);
		break;
		
		case 4:
		effaceFenetre(255,255,255);
		pageJeuTestVA( image);
		break;
		
	}
}


test gereClic1 (test c){
	int x=0, y=0;
	x=abscisseSouris();
	y=ordonneeSouris();
	
	if( x >=310 && x<=505 && y>=150 && y<=350) {
		c.clic1=1;
	}
	  else if(x>=60 && x <= 240 && y>=200 && y<=320) {
		c.clic1=2;
	}
	  else if (x>=300 && x<=470 && y>=200 && y<= 320) {
		
		c.clic1 = 3;
	}

	else if (x>=540 && x<=705 && y>=200 && y<= 320) {
		c.clic1 = 4; 
	}


	return c ;

}

void pagetest(void){
	couleurCourante(198,8,0);
	epaisseurDeTrait(4);
	afficheChaine("Que voulez-vous faire ? ",45,115,500);
	couleurCourante(1,215,88);
	rectangle(100,150,295,350);	
	rectangle(310,150,505,350);
	rectangle(520,150,715,350);
	couleurCourante(0,0,0);
	epaisseurDeTrait(2.5);
	afficheChaine("Test Integrale",25,110,250);
	afficheChaine("Test Specifique",23,320,250);
	afficheChaine("Resultats",20,560,250);
	epaisseurDeTrait(2);
	couleurCourante(4,139,154);
	rectangle(650,0,800,50);
	couleurCourante(0,0,0);
	afficheChaine("Deconnexion",20,665,20);

	
	
}

void choixTest(DonneesImageRGB* memoire,DonneesImageRGB* mouvement,DonneesImageRGB* rapidite) {
	couleurCourante(198,8,0);
	epaisseurDeTrait(4);
	afficheChaine("Quelles aptitudes voulez-vous tester ? ",36,45,450);
	ecrisImage(60,200, memoire->largeurImage, memoire->hauteurImage, memoire->donneesRGB);
	epaisseurDeTrait(3);
	afficheChaine("Memoire",28,90,170);
	afficheChaine("Mobilite",28, 340,170);
	afficheChaine("Test Vitesse Analyse",20,520,170);
	ecrisImage(300,200, mouvement->largeurImage, mouvement->hauteurImage, mouvement->donneesRGB);
	ecrisImage(540,200, rapidite->largeurImage, rapidite->hauteurImage, rapidite->donneesRGB);
	epaisseurDeTrait(2);
	couleurCourante(4,139,154);
	rectangle(650,0,800,50);
	rectangle(0,0,largeurFenetre()-650,hauteurFenetre()-550);
	couleurCourante(0,0,0);	
	afficheChaine("Home",20,largeurFenetre()-765,hauteurFenetre()-580);
	afficheChaine("Deconnexion",20,largeurFenetre()-135,hauteurFenetre()-580);

	
}

void pageJeuMemoire(DonneesImageRGB* image){
	couleurCourante(4,139,154);
	rectangle(0,0,largeurFenetre()-650,hauteurFenetre()-550);
	rectangle(largeurFenetre()-150,0,largeurFenetre(),hauteurFenetre()-550);
	rectangle(largeurFenetre()-150,hauteurFenetre()-50,largeurFenetre(),hauteurFenetre());
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("Home",20,largeurFenetre()-765,hauteurFenetre()-580);
	afficheChaine("Deconnexion",20,largeurFenetre()-135,hauteurFenetre()-580);
	afficheChaine("Resultats",20,largeurFenetre()-120,hauteurFenetre()-30);
	afficheChaine("MEMORY",35,largeurFenetre()-650,hauteurFenetre()-440);
	afficheChaine("NUMBER",35,largeurFenetre()-290,hauteurFenetre()-440);
	ecrisImage(largeurFenetre()-700,hauteurFenetre()-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
	ecrisImage(largeurFenetre()-350,hauteurFenetre()-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
}

void pageJeuMobilite(DonneesImageRGB* image){
	couleurCourante(4,139,154);
	rectangle(0,0,largeurFenetre()-650,hauteurFenetre()-550);
	rectangle(largeurFenetre()-150,0,largeurFenetre(),hauteurFenetre()-550);
	rectangle(largeurFenetre()-150,hauteurFenetre()-50,largeurFenetre(),hauteurFenetre());
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("Home",20,largeurFenetre()-765,hauteurFenetre()-580);
	afficheChaine("Deconnexion",20,largeurFenetre()-135,hauteurFenetre()-580);
	afficheChaine("Resultats",20,largeurFenetre()-120,hauteurFenetre()-30);
	afficheChaine("THE SNAKE",35,largeurFenetre()-685,hauteurFenetre()-440);
	afficheChaine("THE BALL",35,largeurFenetre()-320,hauteurFenetre()-440);
	ecrisImage(largeurFenetre()-700,hauteurFenetre()-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
	ecrisImage(largeurFenetre()-350,hauteurFenetre()-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
}

void pageJeuTestVA(DonneesImageRGB* image){
	couleurCourante(4,139,154);
	rectangle(0,0,largeurFenetre()-650,hauteurFenetre()-550);
	rectangle(largeurFenetre()-150,0,largeurFenetre(),hauteurFenetre()-550);
	rectangle(largeurFenetre()-150,hauteurFenetre()-50,largeurFenetre(),hauteurFenetre());
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("Home",20,largeurFenetre()-765,hauteurFenetre()-580);
	afficheChaine("Deconnexion",20,largeurFenetre()-135,hauteurFenetre()-580);
	afficheChaine("Resultats",20,largeurFenetre()-120,hauteurFenetre()-30);
	afficheChaine("COLOR",35,largeurFenetre()-640,hauteurFenetre()-440);
	afficheChaine("POINT",35,largeurFenetre()-280,hauteurFenetre()-440);
	ecrisImage(largeurFenetre()-700,hauteurFenetre()-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
	ecrisImage(largeurFenetre()-350,hauteurFenetre()-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
}

/*Elsa*/
/*
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
*/
