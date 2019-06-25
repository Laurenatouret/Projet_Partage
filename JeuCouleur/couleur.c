#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <string.h>
#include "../GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include <time.h>
#include "couleur.h"
#define LargeurFenetre 800
#define HauteurFenetre 600


void page(void){
	couleurCourante(44,117,255);
	rectangle(LargeurFenetre-700,HauteurFenetre-550,LargeurFenetre-550,HauteurFenetre-400);
	couleurCourante(1,215,88);
	rectangle(LargeurFenetre-500,HauteurFenetre-550,LargeurFenetre-350,HauteurFenetre-400);
	couleurCourante(198,8,0);
	rectangle(LargeurFenetre-300,HauteurFenetre-550,LargeurFenetre-150,HauteurFenetre-400);
	couleurCourante(0,0,0);
	epaisseurDeTrait(2);
	afficheChaine("De quelle couleur est ecris le mot suivant?",30,LargeurFenetre-770,HauteurFenetre-100);
}
void initableau(char tabCouleur[20]){
	int i;
	for (i=0;i<20;i++){
		tabCouleur[i]=0;
	}
}
void afficheTab(char tabCouleur[20][6]){
	strcpy(tabCouleur[0],"ROUGE");
	strcpy(tabCouleur[1],"BLEU");
	strcpy(tabCouleur[2],"VERT");
	strcpy(tabCouleur[3],"ROUGE");
	strcpy(tabCouleur[4],"BLEU");
	strcpy(tabCouleur[5],"VERT");
	strcpy(tabCouleur[6],"ROUGE");
	strcpy(tabCouleur[7],"BLEU");
	strcpy(tabCouleur[8],"VERT");
	strcpy(tabCouleur[9],"ROUGE");
	strcpy(tabCouleur[10],"BLEU");
	strcpy(tabCouleur[11],"VERT");
	strcpy(tabCouleur[12],"ROUGE");
	strcpy(tabCouleur[13],"BLEU");
	strcpy(tabCouleur[14],"VERT");
	strcpy(tabCouleur[15],"ROUGE");
	strcpy(tabCouleur[16],"BLEU");	
	strcpy(tabCouleur[17],"VERT");	
	strcpy(tabCouleur[18],"ROUGE");
	strcpy(tabCouleur[19],"BLEU");
}

int aleatoire(int max, int min){
	int a;
	a=(rand()%(max-min))+min;
	a=a+1;
	return a;
}
couleur afficheCouleur(couleur c){
	c.tabC[0][0]=44; //bleu
	c.tabC[0][1]=117;
	c.tabC[0][2]=255;
	c.tabC[1][0]=1; //vert
	c.tabC[1][1]=215;
	c.tabC[1][2]=88;
	c.tabC[2][0]=198; //rouge
	c.tabC[2][1]=8;
	c.tabC[2][2]=0;
	c.tabC[3][0]=198;
	c.tabC[3][1]=8;
	c.tabC[3][2]=0;
	c.tabC[4][0]=44;
	c.tabC[4][1]=117;
	c.tabC[4][2]=255;
	c.tabC[5][0]=1;
	c.tabC[5][1]=215;
	c.tabC[5][2]=88;
	c.tabC[6][0]=1;
	c.tabC[6][1]=215;
	c.tabC[6][2]=88;
	c.tabC[7][0]=198;
	c.tabC[7][1]=8;
	c.tabC[7][2]=0;
	c.tabC[8][0]=44;
	c.tabC[8][1]=117;
	c.tabC[8][2]=255;
	c.tabC[9][0]=44;
	c.tabC[9][1]=117;
	c.tabC[9][2]=255;
	c.tabC[10][0]=44;
	c.tabC[10][1]=117;
	c.tabC[10][2]=255;
	c.tabC[11][0]=1;
	c.tabC[11][1]=215;
	c.tabC[11][2]=88;
	c.tabC[12][0]=198;
	c.tabC[12][1]=8;
	c.tabC[12][2]=0;
	c.tabC[13][0]=44;
	c.tabC[13][1]=117;
	c.tabC[13][2]=255;
	c.tabC[14][0]=1;
	c.tabC[14][1]=215;
	c.tabC[14][2]=88;
	c.tabC[15][0]=198;
	c.tabC[15][1]=8;
	c.tabC[15][2]=0;
	c.tabC[16][0]=1;
	c.tabC[16][1]=215;
	c.tabC[16][2]=88;
	c.tabC[17][0]=44;
	c.tabC[17][1]=117;
	c.tabC[17][2]=255;
	c.tabC[18][0]=198;
	c.tabC[18][1]=8;
	c.tabC[18][2]=0;
	c.tabC[19][0]=1;
	c.tabC[19][1]=215;
	c.tabC[19][2]=88;
	return c;
}

verif verifCouleurRectangle1(couleur c,int rectangle, verif V, int aleaC){
		if(c.tabC[aleaC][0]==44 && c.tabC[aleaC][1]==117 && c.tabC[aleaC][2]==255){
			V.point++;
			printf("point= %d\n",V.point);
		}
		else {
			V.faute++;
			printf("faute= %d\n",V.faute);	
		}
	return V;
}
verif verifCouleurRectangle2(couleur c,int rectangle, verif V, int aleaC){
		if(c.tabC[aleaC][0]==1 && c.tabC[aleaC][1]==215 && c.tabC[aleaC][2]==88){
			V.point++;
			printf("point= %d\n",V.point);
		}
		else{
			V.faute++;
			printf("faute=%d\n",V.faute);
		}
	return V;
}
verif verifCouleurRectangle3(couleur c,int rectangle, verif V, int aleaC){
		if(c.tabC[aleaC][0]==198 && c.tabC[aleaC][1]==8 && c.tabC[aleaC][2]==0){
			V.point++;
			printf("point= %d\n",V.point);
		}
		else{
			V.faute++;
			printf("faute= %d\n",V.faute);	
		}
	return V;
}

chrono majChrono(chrono k, int * Page){
	chrono newk;
	newk.min = k.min;
	newk.sec = k.sec+1;
	if(newk.sec == 40){
		//newk.sec = 0;
		//newk.min = newk.min + 1;
		effaceFenetre (255, 255, 255);
		*Page=1;
	}
	return newk;
}

void pageResultat(void){
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("Resultats",65,LargeurFenetre-555,HauteurFenetre-100);
	epaisseurDeTrait(2);
	afficheChaine("Votre score est de:",35,LargeurFenetre-795,HauteurFenetre-200);
	epaisseurDeTrait(1);
	couleurCourante(135,233,144);
	afficheChaine("Points:",25,LargeurFenetre-750,HauteurFenetre-285);
	couleurCourante(4,139,154);
	afficheChaine("Fautes:",25,LargeurFenetre-750,HauteurFenetre-365);
	
	epaisseurDeTrait(8);
	couleurCourante(135,233,144);
	point(LargeurFenetre-760,HauteurFenetre-280);
	
	couleurCourante(4,139,154);
	point(LargeurFenetre-760,HauteurFenetre-360);
	
	couleurCourante(135,233,144);
	rectangle(LargeurFenetre-560,HauteurFenetre-110,LargeurFenetre-275,HauteurFenetre-105);
	rectangle(LargeurFenetre-520,HauteurFenetre-120,LargeurFenetre-315,HauteurFenetre-115);
	
	couleurCourante(4,139,154);
	rectangle(200,100,395,170);
	
	couleurCourante(255,255,255);
	rectangle(203,103,392,167);
	
	couleurCourante(4,139,154);
	rectangle(206,106,389,164);
	
	couleurCourante(135,233,144);
	rectangle(405,100,600,170);
	
	couleurCourante(255,255,255);
	rectangle(408,103,597,167);
	
	couleurCourante(135,233,144);
	rectangle(411,106,594,164);
	
	couleurCourante(0,0,0);
	epaisseurDeTrait(3);
	afficheChaine("REJOUER",15,255,130);
	afficheChaine("RETOUR",15,470,130);
}




