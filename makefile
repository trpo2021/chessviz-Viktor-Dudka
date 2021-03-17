gcc -Wall -Werror -c main.cpp
gcc -Wall -Werror -c chesslab1.cpp
CFLAGS = -Wall -Wextra -Werror

hello: main.o hello.o
        $(CC) $(CFLAGS) -o $@ $^

main.o: main.c
        $(CC) -c $(CFLAGS) -o $@ $<

hello.o: hello.c
        $(CC) -c $(CFLAGS) -o $@ $<

-include main.d hello.d

