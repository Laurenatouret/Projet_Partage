#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../BmpLib.h" // Cet include permet de manipuler des fichiers BMP

#define LargeurFenetre 800
#define HauteurFenetre 600

/*void pageJeuMemoire(DonneesImageRGB* image){
	couleurCourante(4,139,154);
	rectangle(0,0,LargeurFenetre-650,HauteurFenetre-550);
	rectangle(LargeurFenetre-150,0,LargeurFenetre,HauteurFenetre-550);
	rectangle(LargeurFenetre-150,HauteurFenetre-50,LargeurFenetre,HauteurFenetre);
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("Home",20,LargeurFenetre-765,HauteurFenetre-580);
	afficheChaine("Deconnexion",20,LargeurFenetre-135,HauteurFenetre-580);
	afficheChaine("Resultats",20,LargeurFenetre-120,HauteurFenetre-30);
	afficheChaine("MEMORY",35,LargeurFenetre-650,HauteurFenetre-440);
	afficheChaine("NUMBER",35,LargeurFenetre-290,HauteurFenetre-440);
	ecrisImage(LargeurFenetre-700,HauteurFenetre-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
	ecrisImage(LargeurFenetre-350,HauteurFenetre-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
}

void pageJeuMobilite(DonneesImageRGB* image){
	couleurCourante(4,139,154);
	rectangle(0,0,LargeurFenetre-650,HauteurFenetre-550);
	rectangle(LargeurFenetre-150,0,LargeurFenetre,HauteurFenetre-550);
	rectangle(LargeurFenetre-150,HauteurFenetre-50,LargeurFenetre,HauteurFenetre);
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("Home",20,LargeurFenetre-765,HauteurFenetre-580);
	afficheChaine("Deconnexion",20,LargeurFenetre-135,HauteurFenetre-580);
	afficheChaine("Resultats",20,LargeurFenetre-120,HauteurFenetre-30);
	afficheChaine("THE SNAKE",35,LargeurFenetre-685,HauteurFenetre-440);
	afficheChaine("THE BALL",35,LargeurFenetre-320,HauteurFenetre-440);
	ecrisImage(LargeurFenetre-700,HauteurFenetre-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
	ecrisImage(LargeurFenetre-350,HauteurFenetre-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
}

void pageJeuTestVA(DonneesImageRGB* image){
	couleurCourante(4,139,154);
	rectangle(0,0,LargeurFenetre-650,HauteurFenetre-550);
	rectangle(LargeurFenetre-150,0,LargeurFenetre,HauteurFenetre-550);
	rectangle(LargeurFenetre-150,HauteurFenetre-50,LargeurFenetre,HauteurFenetre);
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("Home",20,LargeurFenetre-765,HauteurFenetre-580);
	afficheChaine("Deconnexion",20,LargeurFenetre-135,HauteurFenetre-580);
	afficheChaine("Resultats",20,LargeurFenetre-120,HauteurFenetre-30);
	afficheChaine("COLOR",35,LargeurFenetre-640,HauteurFenetre-440);
	afficheChaine("POINT",35,LargeurFenetre-280,HauteurFenetre-440);
	ecrisImage(LargeurFenetre-700,HauteurFenetre-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
	ecrisImage(LargeurFenetre-350,HauteurFenetre-400,image->largeurImage,image->hauteurImage,image->donneesRGB);
}*/

void snakeN1(void){
	couleurCourante(135, 233, 144);
	rectangle(LargeurFenetre-450,HauteurFenetre-325,LargeurFenetre-350,HauteurFenetre);
	rectangle(LargeurFenetre-780,HauteurFenetre-325,LargeurFenetre-350,HauteurFenetre-250);
	rectangle(LargeurFenetre-780,HauteurFenetre-450,LargeurFenetre-680,HauteurFenetre-250);
	rectangle(LargeurFenetre-780,HauteurFenetre-525,LargeurFenetre-50,HauteurFenetre-450);
	rectangle(LargeurFenetre-285,HauteurFenetre-190,LargeurFenetre-55,HauteurFenetre-185);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Niveau 2",20,LargeurFenetre-145,HauteurFenetre-445);
	rectangle(LargeurFenetre-145,HauteurFenetre-525,LargeurFenetre-50,HauteurFenetre-450);
	epaisseurDeTrait(3);
	afficheChaine("NIVEAU 1",45,LargeurFenetre-280,HauteurFenetre-180);
}
void pointN1(int px1,int py1){
	epaisseurDeTrait(30);
	couleurCourante(0,0,0);
	point(px1,py1);
	printf("%d,%d\n",px1,py1);	
}
int etatPoint1(int px1,int py1,int dedans){
	if((px1>=LargeurFenetre-450+15 && py1>=HauteurFenetre-250+15 && px1<=LargeurFenetre-350-15 && px1<=HauteurFenetre-15)||(px1>=LargeurFenetre-780+15 && py1>=HauteurFenetre-325+15 && px1<=LargeurFenetre-350-15 && py1<=HauteurFenetre-250-15)||(px1>=LargeurFenetre-780+15 && py1>=HauteurFenetre-450+15 && px1<=LargeurFenetre-680-15 && py1<=HauteurFenetre-325-15)||(px1>=LargeurFenetre-780+15 && py1>=HauteurFenetre-525+15 && px1<=LargeurFenetre-50-15 && py1<=HauteurFenetre-450-15)){
		dedans=0;
	}
	else{
		dedans=1;
	}
	return dedans;
}
int tempsErreur(int dedans, int erreur){
	if(dedans==1){
		erreur++;
	}
	else{
	}
	
	return erreur;
}

void snakeN2(void){
	couleurCourante(31, 160, 85);
	rectangle(LargeurFenetre-780,HauteurFenetre-65,LargeurFenetre-50,HauteurFenetre-25);
	rectangle(LargeurFenetre-780,HauteurFenetre-130,LargeurFenetre-740,HauteurFenetre-65);
	rectangle(LargeurFenetre-780,HauteurFenetre-170,LargeurFenetre-50,HauteurFenetre-130);
	rectangle(LargeurFenetre-95,HauteurFenetre-250,LargeurFenetre-50,HauteurFenetre-170);
	rectangle(LargeurFenetre-780,HauteurFenetre-275,LargeurFenetre-50,HauteurFenetre-235);
	rectangle(LargeurFenetre-780,HauteurFenetre-65,LargeurFenetre-740,HauteurFenetre-25);
	rectangle(LargeurFenetre-780,HauteurFenetre-365,LargeurFenetre-740,HauteurFenetre-250);
	rectangle(LargeurFenetre-780,HauteurFenetre-400,LargeurFenetre-50,HauteurFenetre-365);
	rectangle(LargeurFenetre-75,HauteurFenetre-480,LargeurFenetre-50,HauteurFenetre-400);
	rectangle(LargeurFenetre-780,HauteurFenetre-510,LargeurFenetre-50,HauteurFenetre-480);
	rectangle(LargeurFenetre-780,HauteurFenetre-560,LargeurFenetre-755,HauteurFenetre-510);
	rectangle(LargeurFenetre-780,HauteurFenetre-585,LargeurFenetre-50,HauteurFenetre-560);
	rectangle(LargeurFenetre-505,HauteurFenetre-340,LargeurFenetre-260,HauteurFenetre-335);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Niveau 3",15,LargeurFenetre-120,HauteurFenetre-555);
	rectangle(LargeurFenetre-120,HauteurFenetre-585,LargeurFenetre-50,HauteurFenetre-560);
	epaisseurDeTrait(3);
	afficheChaine("NIVEAU 2",45,LargeurFenetre-500,HauteurFenetre-330);
}
void pointN2(int px2,int py2){
	epaisseurDeTrait(15);
	couleurCourante(0,0,0);
	point(px2,py2);
	printf("%d,%d\n",px2,py2);	
}
int etatPoint2(int px2,int py2,int dedans){
	if((px2>LargeurFenetre-780+7 && py2>HauteurFenetre-65+7 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-25-7)||(px2>LargeurFenetre-780+15 && py2>HauteurFenetre-130+7 && px2<LargeurFenetre-740-7 && py2<HauteurFenetre-65-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-170+7 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-130-7)||(px2>LargeurFenetre-95+7 && py2>HauteurFenetre-250+7 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-170-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-275+15 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-235-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-65+7 && px2<LargeurFenetre-740-7 && py2<HauteurFenetre-25-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-365+7 && px2<LargeurFenetre-740-7 && py2<HauteurFenetre-250-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-400+7 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-365-7)||(px2>LargeurFenetre-75+7 && py2>HauteurFenetre-480+7 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-400-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-510+7 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-480-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-560+7 && px2<LargeurFenetre-755-7 && py2<HauteurFenetre-510-7)||(px2>LargeurFenetre-780+7 && py2>HauteurFenetre-585+7 && px2<LargeurFenetre-50-7 && py2<HauteurFenetre-560-7)){
		dedans=0;
	}
	else{
		dedans=1;
	}
	return dedans;
}


void snakeN3(void){
	couleurCourante(4, 139, 154);
	rectangle(LargeurFenetre-790,HauteurFenetre-150,LargeurFenetre-760,HauteurFenetre-40);
	rectangle(LargeurFenetre-790,HauteurFenetre-170,LargeurFenetre-280,HauteurFenetre-150);
	rectangle(LargeurFenetre-280,HauteurFenetre-170,LargeurFenetre-250,HauteurFenetre-85);
	rectangle(LargeurFenetre-480,HauteurFenetre-85,LargeurFenetre-250,HauteurFenetre-60);
	rectangle(LargeurFenetre-520,HauteurFenetre-115,LargeurFenetre-480,HauteurFenetre-60);
	rectangle(LargeurFenetre-670,HauteurFenetre-135,LargeurFenetre-480,HauteurFenetre-115);
	rectangle(LargeurFenetre-670,HauteurFenetre-135,LargeurFenetre-640,HauteurFenetre-25);
	rectangle(LargeurFenetre-670,HauteurFenetre-25,LargeurFenetre-40,HauteurFenetre-5);
	rectangle(LargeurFenetre-65,HauteurFenetre-100,LargeurFenetre-40,HauteurFenetre-25);
	rectangle(LargeurFenetre-190,HauteurFenetre-120,LargeurFenetre-40,HauteurFenetre-100);
	rectangle(LargeurFenetre-190,HauteurFenetre-200,LargeurFenetre-160,HauteurFenetre-120);
	rectangle(LargeurFenetre-750,HauteurFenetre-220,LargeurFenetre-160,HauteurFenetre-200);
	rectangle(LargeurFenetre-750,HauteurFenetre-305,LargeurFenetre-700,HauteurFenetre-220);
	rectangle(LargeurFenetre-750,HauteurFenetre-305,LargeurFenetre-430,HauteurFenetre-280);
	rectangle(LargeurFenetre-430,HauteurFenetre-380,LargeurFenetre-395,HauteurFenetre-280);
	rectangle(LargeurFenetre-430,HauteurFenetre-400,LargeurFenetre-220,HauteurFenetre-380);
	rectangle(LargeurFenetre-245,HauteurFenetre-380,LargeurFenetre-220,HauteurFenetre-260);
	rectangle(LargeurFenetre-245,HauteurFenetre-260,LargeurFenetre-100,HauteurFenetre-240);
	rectangle(LargeurFenetre-125,HauteurFenetre-450,LargeurFenetre-100,HauteurFenetre-240);
	rectangle(LargeurFenetre-765,HauteurFenetre-470,LargeurFenetre-100,HauteurFenetre-450);
	rectangle(LargeurFenetre-765,HauteurFenetre-555,LargeurFenetre-730,HauteurFenetre-470);
	rectangle(LargeurFenetre-765,HauteurFenetre-575,LargeurFenetre-145,HauteurFenetre-555);
	rectangle(LargeurFenetre-745,HauteurFenetre-405,LargeurFenetre-500,HauteurFenetre-400);
	couleurCourante(0,0,0);
	epaisseurDeTrait(1);
	afficheChaine("Resultats",15,LargeurFenetre-210,HauteurFenetre-550);
	rectangle(LargeurFenetre-210,HauteurFenetre-575,LargeurFenetre-145,HauteurFenetre-555);
	epaisseurDeTrait(3);
	afficheChaine("NIVEAU 3",45,LargeurFenetre-740,HauteurFenetre-395);
}
void pointN3(int px3,int py3){
	epaisseurDeTrait(10);
	couleurCourante(0,0,0);
	point(px3,py3);
	printf("%d,%d\n",px3,py3);	
}	
int etatPoint3(int px3,int py3,int dedans){
	if((px3>LargeurFenetre-790+5 && py3>HauteurFenetre-150+5 && px3<LargeurFenetre-760-5 && py3<HauteurFenetre-40-5)||(px3>LargeurFenetre-790+5 && py3>HauteurFenetre-170+5 && px3<LargeurFenetre-280-5 && py3<HauteurFenetre-150-5)||(px3>LargeurFenetre-280+5 && py3>HauteurFenetre-170+5 && px3<LargeurFenetre-250-5 && py3<HauteurFenetre-85-5)||(px3>LargeurFenetre-480+5 && py3>HauteurFenetre-85+5 && px3<LargeurFenetre-250-5 && py3<HauteurFenetre-60-5)||(px3>LargeurFenetre-520+5 && py3>HauteurFenetre-115+5 && px3<LargeurFenetre-480-5 && py3<HauteurFenetre-60-5)||(px3>LargeurFenetre-670+5 && py3>HauteurFenetre-135+5 && px3<LargeurFenetre-480-5 && py3<HauteurFenetre-115-5)||(px3>LargeurFenetre-670+5 && py3>HauteurFenetre-135+5 && px3<LargeurFenetre-640-5 && py3<HauteurFenetre-25-5)||(px3>LargeurFenetre-670+5 && py3>HauteurFenetre-25+5 && px3<LargeurFenetre-40-5 && py3<HauteurFenetre-5-5)||(px3>LargeurFenetre-65+5 && py3>HauteurFenetre-100+5 && px3<LargeurFenetre-40-5 && py3<HauteurFenetre-25-5)||(px3>LargeurFenetre-190+5 && py3>HauteurFenetre-120+5 && px3<LargeurFenetre-40-5 && py3<HauteurFenetre-100-5)||(px3>LargeurFenetre-190+5 && py3>HauteurFenetre-200+5 && px3<LargeurFenetre-160-5 && py3<HauteurFenetre-120-5)||(px3>LargeurFenetre-750+5 && py3>HauteurFenetre-220+5 && px3<LargeurFenetre-160-5 && py3<HauteurFenetre-200-5)||(px3>LargeurFenetre-750+5 && py3>HauteurFenetre-305+5 && px3<LargeurFenetre-700-5 && py3<HauteurFenetre-220-5)||(px3>LargeurFenetre-750+5 && py3>HauteurFenetre-305+5 && px3<LargeurFenetre-430-5 && py3<HauteurFenetre-280-5)||(px3>LargeurFenetre-430+5 && py3>HauteurFenetre-380+5 && px3<LargeurFenetre-395-5 && py3<HauteurFenetre-280-5)||(px3>LargeurFenetre-430+5 && py3>HauteurFenetre-400+5 && px3<LargeurFenetre-220-5 && py3<HauteurFenetre-380-5)||(px3>LargeurFenetre-245+5 && py3>HauteurFenetre-380+5 && px3<LargeurFenetre-220-5 && py3<HauteurFenetre-260-5)||(px3>LargeurFenetre-245+5 && py3>HauteurFenetre-260+5 && px3<LargeurFenetre-100-5 && py3<HauteurFenetre-240-5)||(px3>LargeurFenetre-125+5 && py3>HauteurFenetre-450+5 && px3<LargeurFenetre-100-5 && py3<HauteurFenetre-240-5)||(px3>LargeurFenetre-765+5 && py3>HauteurFenetre-470+5 && px3<LargeurFenetre-100-5 && py3<HauteurFenetre-450-5)||(px3>LargeurFenetre-765+5 && py3>HauteurFenetre-555+5 && px3<LargeurFenetre-730-5 && py3<HauteurFenetre-470-5)||(px3>LargeurFenetre-765+5 && py3>HauteurFenetre-575+5 && px3<LargeurFenetre-145-5 && py3<HauteurFenetre-555-5)){
		dedans=0;
	}
	else{
		dedans=1;
	}
	return dedans;
}

void pageResultat(void){
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("Resultats",65,LargeurFenetre-555,HauteurFenetre-100);
	epaisseurDeTrait(2);
	afficheChaine("Votre score est de:",35,LargeurFenetre-795,HauteurFenetre-200);
	epaisseurDeTrait(1);
	couleurCourante(135, 233, 144);
	afficheChaine("Niveau 1:",25,LargeurFenetre-750,HauteurFenetre-285);
	couleurCourante(31, 160, 85);
	afficheChaine("Niveau 2:",25,LargeurFenetre-750,HauteurFenetre-365);
	couleurCourante(4, 139, 154);
	afficheChaine("Niveau 3:",25,LargeurFenetre-750,HauteurFenetre-445);
	epaisseurDeTrait(8);
	couleurCourante(135, 233, 144);
	point(LargeurFenetre-760,HauteurFenetre-280);
	couleurCourante(31, 160, 85);
	point(LargeurFenetre-760,HauteurFenetre-360);
	couleurCourante(4, 139, 154);
	point(LargeurFenetre-760,HauteurFenetre-440);
	couleurCourante(31, 160, 85);
	rectangle(LargeurFenetre-560,HauteurFenetre-110,LargeurFenetre-275,HauteurFenetre-105);
	rectangle(LargeurFenetre-520,HauteurFenetre-120,LargeurFenetre-315,HauteurFenetre-115);
	rectangle(LargeurFenetre-370,HauteurFenetre-400,LargeurFenetre-90,HauteurFenetre-350);
	couleurCourante(255,255,255);
	rectangle(LargeurFenetre-364,HauteurFenetre-396,LargeurFenetre-94,HauteurFenetre-354);
	
	couleurCourante(4,139,154);
	rectangle(200,40,395,110);
	
	couleurCourante(255,255,255);
	rectangle(203,43,392,107);
	
	couleurCourante(4,139,154);
	rectangle(206,46,389,104);
	
	couleurCourante(135,233,144);
	rectangle(405,40,600,110);
	
	couleurCourante(255,255,255);
	rectangle(408,43,597,107);
	
	couleurCourante(135,233,144);
	rectangle(411,46,594,104);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("REJOUER",15,255,68);
	afficheChaine("RETOUR",15,470,68);
	
}
