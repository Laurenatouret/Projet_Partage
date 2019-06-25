void afficheTab(char tabCouleur[20][6]);
int aleatoire(int max, int min);
void page(void);

typedef struct couleur{
	int tabC[20][3];
}couleur;

typedef struct verif{
	int faute;
	int point;
}verif;

typedef struct chrono{
	int min;
	int sec;
}chrono;

verif verifCouleurRectangle1(couleur c,int rectangle, verif V, int aleaC);
verif verifCouleurRectangle2(couleur c,int rectangle, verif V, int aleaC);
verif verifCouleurRectangle3(couleur c,int rectangle, verif V, int aleaC);
couleur afficheCouleur(couleur c);
chrono majChrono(chrono k, int * Page);
void pageResultat(void);
