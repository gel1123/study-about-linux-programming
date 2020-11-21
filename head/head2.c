#include <stdio.h>
#include <stdlib.h>

static void do_head(FILE *f, long n);

int
main(int argc, char *argv[])
{
	if (argc == 2) 	do_head(stdin, atol(argv[1]));
	if (argc < 2) exit(1);
	int i;
	for (i=2; argc > i; i++) {
		FILE *f = fopen(argv[i], "r");
		if (f) do_head(f, atol(argv[1]));

	}
}

static void do_head(FILE *f, long n)
{
	int c;
	if (n < 1) exit(1);
	while ((c=getc(f)) !=EOF) {
		if (putchar(c) < 0) exit(1);
		if (c == '\n') {
			n--;
			if (n==0) exit(0);
		}
	}
}
