

all: chessviz-Viktor-Dudka

chessviz-Viktor-Dudka:chesslab1.cpp 
 g++ $(CFLAGS) main.o lib.o -o chessviz-Viktor-Dudka

clean: rm -rf *.o chessviz-Viktor-Dudka 
