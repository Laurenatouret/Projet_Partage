#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../ESLib.h" // Pour utiliser valeurAleatoire()



// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 800
#define HauteurFenetre 600




struct coordBalles{
	int x;
	int y;
	int b;
	int vx;
	int vy;
};
typedef struct coordBalles coordBalles;


struct CERCLE{
	float x;
	float y;
};
typedef struct CERCLE structure;

void croixStart();
void connexion();

void cercle(float centreX, float centreY, float rayon);

void pointCouleur(structure *point);
void affichageScore();
void curseur (int x1croix1,int y1croix1,int x2croix1,int y2croix1);
int obstacle (coordBalles tab[30],int x1croix1,int y1croix1,int x2croix1,int y2croix1);
void initTab(coordBalles tab[30]);
void multiBalles();
void afficheBalles(coordBalles tab[30]);
void bougeBalles(coordBalles tab[30]);
