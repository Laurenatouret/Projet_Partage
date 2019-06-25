#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "../tpGfx/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "../tpGfx/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "../tpGfx/ESLib.h" // Pour utiliser valeurAleatoire()

typedef struct Clic{
	int clic1;

}test;
 
void pagetest(void);
void choixTest(DonneesImageRGB* memoire,DonneesImageRGB* mouvement,DonneesImageRGB* rapidite);
void pageJeuMobilite(DonneesImageRGB* image);
void pageJeuTestVA(DonneesImageRGB* image);
void pageJeuMemoire(DonneesImageRGB* image);
void gereClic(test c, DonneesImageRGB* image,DonneesImageRGB* memoire,DonneesImageRGB* mouvement,DonneesImageRGB* rapidite);
void memory (DonneesImageRGB* loic);



test gereClic1 (test c);

