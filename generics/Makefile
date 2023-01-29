
program: main.o
	gcc -o $@ $^

%.o: %.c
	gcc -c -o $@ $< -Wall -Wextra -Wpedantic -Wconversion -Wshadow

clean:
	$(RM) *.o program

