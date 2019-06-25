Projet: main.o projet.o ../libisentlib.a
	gcc main.o projet.o -o Projet ../libisentlib.a -lm -lglut -lGL -lX11
main.o: main.c ../GfxLib.h ../BmpLib.h
	gcc -g -Wall -c main.c
projet.o: projet.c ../GfxLib.h ../BmpLib.h
	gcc -g -Wall -c projet.c
clean:
	rm projet *.o
