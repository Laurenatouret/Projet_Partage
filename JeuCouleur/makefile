Couleur: main.o couleur.o ../libisentlib.a
	gcc -g main.o couleur.o -o Couleur ../libisentlib.a -lm -lglut -lGL -lX11
main.o: main.c ../GfxLib.h ../BmpLib.h
	gcc -g -Wall -c main.c
couleur.o: couleur.c ../GfxLib.h ../BmpLib.h
	gcc -g -Wall -c couleur.c
clean:
	rm couleur *.o

