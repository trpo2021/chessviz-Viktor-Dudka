CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

hello: main.o hello.o
        $(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
        $(CC) -c $(CFLAGS) -o $@ $<

hello.o: hello.cpp
        $(CC) -c $(CFLAGS) -o $@ $<
 -include main.d hello.d
