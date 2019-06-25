#include "mem.h"

void iniEtat( DonneesImageRGB* dos, carte c, carte tabMel[3][4]){
	if(tabMel[0][0].Etat == 0){
		ecrisImage(75,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[0][1].Etat == 0){
		ecrisImage(250,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[0][2].Etat == 0){
		ecrisImage(425,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[0][3].Etat == 0){
		ecrisImage(600,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][0].Etat == 0){
		ecrisImage(75,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][1].Etat == 0){
		ecrisImage(250,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][2].Etat == 0){
		ecrisImage(425,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][3].Etat == 0){
		ecrisImage(600,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][0].Etat == 0){
		ecrisImage(75,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][1].Etat == 0){
		ecrisImage(250,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][2].Etat == 0){
		ecrisImage(425,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][3].Etat == 0){
		ecrisImage(600,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	} 
}

//afficher carte de dos
void afficheDos( DonneesImageRGB* dos, carte c, carte tabMel[3][4]){
	if(tabMel[0][0].etat == 0){
		ecrisImage(75,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[0][1].etat == 0){
		ecrisImage(250,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[0][2].etat == 0){
		ecrisImage(425,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[0][3].etat == 0){
		ecrisImage(600,55, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][0].etat == 0){
		ecrisImage(75,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][1].etat == 0){
		ecrisImage(250,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][2].etat == 0){
		ecrisImage(425,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[1][3].etat == 0){
		ecrisImage(600,230, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][0].etat == 0){
		ecrisImage(75,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][1].etat == 0){
		ecrisImage(250,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][2].etat == 0){
		ecrisImage(425,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	}
	if(tabMel[2][3].etat == 0){
		ecrisImage(600,405, dos->largeurImage, dos->hauteurImage, dos->donneesRGB);
	} 
}
 
//ini position des cartes
carte initCarte(carte c){
	c.etat=0;
	int i=0;
	int j=0;
	for(i=0; i<12; i++){
		for(j=0;j<4;j++){
			c.position[i][j]=0;
			c.ID=0;
		}
	}	
	return c;
}
 
//ini tableau etat carte
void iniTab(carte initTab[3][4],carte c){
	int i=0;
	int j=0;
	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			initTab[i][j].etat=0;
		}
	}
}

// ini tableau carte melanger
void iniMel(carte tabMel[3][4],carte c){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++)	{
					tabMel[i][j].etat= 0;
				}
		printf("\n");
	}
}


//melanger les cartes
void mel(carte initTab[3][4], carte tabMel[3][4],carte c){
	int i=0;
	int j=0;
	int x=0;
	int y=0;
	
	for (i=0;i<3;i++){
		for(j=0;j<4;j++){
			x=rand()%3;
			y=rand()%4;
			//printf("initTab = %d\n", initTab[x][y].etat);
			while(initTab[x][y].Etat == -999){
				x=rand()%3;
				y=rand()%4;
				//printf("rerand\n");
			}
			tabMel[i][j].ID = initTab[x][y].ID;
			tabMel[i][j] = initTab[x][y];
			initTab[x][y].Etat= -999;
			printf("initTab[%d][%d] = %d\n", x,y,initTab[x][y].Etat);
		}
	}
}

//assimiler une image à un placement
//assimiler une ID a un nombre
void placement(carte c,  carte tabMel[3][4], carte initTab[3][4]){

	initTab[0][0].image=lisBMPRGB("../../loic.bmp");
		initTab[0][0].ID = 1;
	initTab[0][1].image=lisBMPRGB("../../loic.bmp");
		initTab[0][1].ID = 1;
	initTab[0][2].image=lisBMPRGB("../../antoine.bmp");
		initTab[0][2].ID = 2;
	initTab[0][3].image=lisBMPRGB("../../antoine.bmp");
		initTab[0][3].ID = 2;
	initTab[1][0].image=lisBMPRGB("../../jules.bmp");
		initTab[1][0].ID = 3;
	initTab[1][1].image=lisBMPRGB("../../jules.bmp");
		initTab[1][1].ID = 3;
	initTab[1][2].image=lisBMPRGB("../../mat.bmp");
		initTab[1][2].ID = 4;
	initTab[1][3].image=lisBMPRGB("../../mat.bmp");
		initTab[1][3].ID = 4;
	initTab[2][0].image=lisBMPRGB("../../william.bmp");
		initTab[2][0].ID = 5;
	initTab[2][1].image=lisBMPRGB("../../william.bmp");
		initTab[2][1].ID = 5;
	initTab[2][2].image=lisBMPRGB("../../louis.bmp");
		initTab[2][2].ID = 6;
	initTab[2][3].image=lisBMPRGB("../../louis.bmp");
		initTab[2][3].ID = 6;
	
}

//affiche image si etat = 1
void afficheImage(carte c,	carte tabMel[3][4]){
	if(tabMel[0][0].etat == 1 || tabMel[0][0].etat == 2 ){
		ecrisImage(75,55,tabMel[0][0].image->largeurImage, tabMel[0][0].image->hauteurImage, tabMel[0][0].image->donneesRGB);
	}
	if(tabMel[0][1].etat == 1 || tabMel[0][1].etat == 2){
		ecrisImage(250,55,tabMel[0][1].image->largeurImage, tabMel[0][1].image->hauteurImage, tabMel[0][1].image->donneesRGB);
	}
	if(tabMel[0][2].etat == 1 || tabMel[0][2].etat == 2){
		ecrisImage(425,55,tabMel[0][2].image->largeurImage, tabMel[0][2].image->hauteurImage, tabMel[0][2].image->donneesRGB);
	}
	if(tabMel[0][3].etat == 1 || tabMel[0][3].etat == 2){
		ecrisImage(600,55,tabMel[0][3].image->largeurImage, tabMel[0][3].image->hauteurImage, tabMel[0][3].image->donneesRGB);
	}
	if(tabMel[1][0].etat == 1 || tabMel[1][0].etat == 2){
		ecrisImage(75,230,tabMel[1][0].image->largeurImage, tabMel[1][0].image->hauteurImage, tabMel[1][0].image->donneesRGB);
	}
	if(tabMel[1][1].etat == 1 || tabMel[1][1].etat == 2){
		ecrisImage(250,230,tabMel[1][1].image->largeurImage, tabMel[1][1].image->hauteurImage, tabMel[1][1].image->donneesRGB);
	}
	if(tabMel[1][2].etat == 1 || tabMel[1][2].etat == 2){
		ecrisImage(425,230,tabMel[1][2].image->largeurImage, tabMel[1][2].image->hauteurImage, tabMel[1][2].image->donneesRGB);
	}
	if(tabMel[1][3].etat == 1 || tabMel[1][3].etat == 2){
		ecrisImage(600,230,tabMel[1][3].image->largeurImage, tabMel[1][3].image->hauteurImage, tabMel[1][3].image->donneesRGB);
	}
	if(tabMel[2][0].etat == 1 || tabMel[2][0].etat == 2){
		ecrisImage(75,405,tabMel[2][0].image->largeurImage, tabMel[2][0].image->hauteurImage, tabMel[2][0].image->donneesRGB);
	}
	if(tabMel[2][1].etat == 1 || tabMel[2][1].etat == 2){
		ecrisImage(250,405,tabMel[2][1].image->largeurImage, tabMel[2][1].image->hauteurImage, tabMel[2][1].image->donneesRGB);
	}
	if(tabMel[2][2].etat == 1 || tabMel[2][2].etat == 2){
		ecrisImage(425,405,tabMel[2][2].image->largeurImage, tabMel[2][2].image->hauteurImage, tabMel[2][2].image->donneesRGB);
	}
	if(tabMel[2][3].etat == 1 || tabMel[2][3].etat == 2){
		ecrisImage(600,405,tabMel[2][3].image->largeurImage, tabMel[2][3].image->hauteurImage, tabMel[2][3].image->donneesRGB);
	}
}

//clique sur une carte --> etat =1
void Etat(DonneesImageRGB* dos,carte tabMel[3][4], carte c){
	int x=0;
	int y=0;
	x=abscisseSouris();
	y=ordonneeSouris();
	if(75<x && x<75+dos->largeurImage && 55<y && y<55+dos->hauteurImage){
		tabMel[0][0].etat = 1;
	}
	else if(250<x && x<250 + dos->largeurImage && 55<y && y<55+dos->hauteurImage){
		tabMel[0][1].etat = 1;
	}
	else if(425<x && x<425+dos->largeurImage && 55<y && y<55+dos->hauteurImage){
		tabMel[0][2].etat = 1;
	}
	else if(600<x && x<600+dos->largeurImage && 55<y && y<55+dos->hauteurImage){
		tabMel[0][3].etat = 1;
	}
	else if(75<x && x<75+dos->largeurImage && 230<y && y<230+dos->hauteurImage){
		tabMel[1][0].etat = 1;
	}
	else if(250<x && x<250+dos->largeurImage && 230<y && y<230+dos->hauteurImage){
		tabMel[1][1].etat = 1;
	}
	else if(425<x && x<475+dos->largeurImage && 230<y && y<230+dos->hauteurImage){
		tabMel[1][2].etat = 1;
	}
	else if(600<x && x<600+dos->largeurImage && 230<y && y<230+dos->hauteurImage){
		tabMel[1][3].etat = 1;
	}
	else if(75<x && x<75+dos->largeurImage && 405<y && y<405+dos->hauteurImage){
		tabMel[2][0].etat = 1;
	}
	else if(250<x && x<250+dos->largeurImage && 405<y && y<405+dos->hauteurImage){
		tabMel[2][1].etat = 1;
	}
	else if(425<x && x<425+dos->largeurImage && 405<y && y<405+dos->hauteurImage){
		tabMel[2][2].etat = 1;
	}
	else if(600<x && x<600+dos->largeurImage && 405<y && y<405+dos->hauteurImage){
		tabMel[2][3].etat = 1;
	}
	
}

void condition(carte tabMel[3][4], carte c){
	int i1=0;
	int j1=0;
	int i2=0;
	int j2=0;
	int cpt=0;
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
		if(tabMel[i][j].etat==1 && cpt==0){
			i1 = i;
			j1=j;
			cpt++;
		}
		if(tabMel[i][j].etat==1 && cpt==1){
			j2=j;
			i2=i;
		}
		}
	}
	if(tabMel[i1][j1].ID==tabMel[i2][j2].ID){
		tabMel[i2][j2].etat = 2;
		tabMel[i1][j1].etat = 2;

	}
	else{
		c.erreur = c.erreur+1;
		printf("erreur : %d\n", c.erreur);
	}
}

carte nettoie (carte tabMel[3][4], carte c){
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			if(tabMel[i][j].etat == 1){
				tabMel[i][j].etat = 0;
			}
		}
	}
	return c;
}

void printfTab(carte tabMel[3][4]){
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			printf("tabMel[%d][%d] = %d\n", i, j, tabMel[i][j].etat);
		}
	}
	printf("\n");
}

void final(carte tabMel[3][4], carte c){
	for(int i=0; i<3; i++){
		for(int j=0; j<4; j++){
			if(tabMel[i][j].etat!=2){
				j=3;
				i=2;
			}
			else{
				termineBoucleEvenements();
			}
		}
	}
}	

void printfErreur(carte c){
	printf("erreur : %d\n", c.erreur);
}
						


