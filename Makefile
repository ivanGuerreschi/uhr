all: uhr

uhr: uhr.c
	$(CC) -g -ggdb uhr.c -Wall -Werror -pedantic -std=c11 -O2 -o uhr

clean:
	rm -rf uhr
