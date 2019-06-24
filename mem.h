#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include "../tpGfx/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../tpGfx/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../tpGfx/ESLib.h" // Pour utiliser valeurAleatoire()


typedef struct Carte {
	int etat; // selectionnee ou non
	int Etat;
	int position [12][4];
	int ID;
	DonneesImageRGB* image;
}carte;

void afficheDos( DonneesImageRGB* dos, carte c, carte tabMel[3][4]);
carte initCarte(carte c);
void iniTab(carte initTab[3][4],carte c);
void iniMel(carte tabMel[3][4],carte c);
void iniEtat( DonneesImageRGB* dos, carte c, carte tabMel[3][4]);
void afficheImage(carte c,	carte tabMel[3][4]);
void placement(carte c, carte tabMel[3][4], carte initTab[3][4]);
void mel(carte initTab[3][4], carte tabMel[3][4],carte c);
void Etat(DonneesImageRGB* dos,carte tabMel[3][4], carte c);
void condition(carte tabMel[3][4], carte c);
