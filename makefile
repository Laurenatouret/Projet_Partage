Memory: mainMem.o memory.o ../tpGfx/libisentlib.a
	gcc mainMem.o memory.o  -o mainMem ../tpGfx/libisentlib.a -lm -lglut -lGL -lX11
	./Memory

mainMem.o: mainMem.c ../tpGfx/BmpLib.h ../tpGfx/GfxLib.h ../tpGfx/ESLib.h
	gcc -g -Wall -c mainMem.c
	
memory.o: memory.c ../tpGfx/BmpLib.h ../tpGfx/GfxLib.h ../tpGfx/ESLib.h
	gcc -g -Wall -c memory.c


	

clean:
	rm mainMem *.o
