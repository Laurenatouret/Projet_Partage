run: pagestart
	./pagestart

pagestart: pagestart.o source.o ../libisentlib.a
	gcc pagestart.o source.o -o pagestart ../libisentlib.a -lm -lglut -lGL -lX11

pagestart.o: pagestart.c ../BmpLib.h  ../GfxLib.h ../ESLib.h
	gcc -g -Wall -c pagestart.c
	
source.o: source.c ../BmpLib.h  ../GfxLib.h ../ESLib.h
	gcc -g -Wall -c source.c

clean: 
	rm pagestart *.o

