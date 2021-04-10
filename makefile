CFLAGS=-Wall -Wextra -Werror
CPPFLAGS=-MMD
CC=g++

hello: main.o hello.o 
	 $(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
	 $(CC) -c $(CFLAGS) -o $@ $<

libhello.a: hello.o
	ar rcs $@ $^

hello.o: hello.cpp
	 $(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

 -include main.d hello.d
