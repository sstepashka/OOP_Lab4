rm -rf *.o
gcc -g -O -c Shape.c -g -O -c Cyrcle.c -g -O -c main.c -g -O -c Rect.c -g -O -c Box.c -g -O -c Composite.c
gcc *.o -o a.out
./a.out
