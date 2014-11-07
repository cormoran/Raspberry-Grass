.PHONY:all
all:Test1.out

Test1.out:Test1.cpp Glcd.o M014C9163SPI.o framebuffer.o
	g++ -Wall -o Test1.out Test1.cpp Glcd.o M014C9163SPI.o framebuffer.o -lbcm2835

Glcd.o : ../../Library/Glcd.cpp
	g++ -Wall -c ../../Library/Glcd.cpp -lbcm2835

M014C9163SPI.o : ../../Library/M014C9163SPI/M014C9163SPI.cpp
	g++ -Wall -c ../../Library/M014C9163SPI/M014C9163SPI.cpp -lbcm2835

framebuffer.o : ../../Library/FrameBuffer/framebuffer.cpp
	g++ -Wall -c ../../Library/FrameBuffer/framebuffer.cpp

Glcd.o : ../../Library/M014C9163SPI/M014C9163SPI.h

M014C9163SPI.o:../../Library/M014C9163SPI/M014C9163SPI.h

framebuffer.o:../../Library/FrameBuffer/framebuffer.h

.PHONY:clean
clean:
	rm -f *.o
