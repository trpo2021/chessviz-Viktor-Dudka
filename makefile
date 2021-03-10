

all: chessviz-Viktor-Dudka

chessviz-Viktor-Dudka:main.o foo.o 
 gcc main.o foo.o -o chessviz-Viktor-Dudka.exe

main.o:chesslab1.cpp
 gcc -c chesslab1.cpp
foo.o:foo.c
 gcc -c foo.c
clean: 
 rm -rf *.o*.exe 
