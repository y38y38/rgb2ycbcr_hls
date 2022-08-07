all:main.c
		gcc -g -o rgb2ycbcr -c main.c


clean:
		rm -f rgb2ycbcr *.o
