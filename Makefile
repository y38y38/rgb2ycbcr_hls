all:main.o rgb2ycbcr.o
		gcc -g -o rgb2ycbcr  main.o rgb2ycbcr.o

main.o:main.c
		gcc -g  -c main.c

rgb2ycbcr.o:rgb2ycbcr.c
		gcc -g  -c rgb2ycbcr.c

clean:
		rm -f rgb2ycbcr *.o
