a.out:		HW2.o
		gcc -o a.out HW2.o

HW2.o:		HW2.c
		gcc -c HW2.c

clean:
		rm *.o
		rm a.out
