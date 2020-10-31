/**
 * @file cat2.0.0.c
 * @brief repoduce "cat" ( stdlib.version )
 * @author gel1123
 * @date 2020-10-31
 */


#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	int i;
	for (i=1; i<argc; i++) {
		FILE *f;
		int c;
		f = fopen(argv[i], "r");
		if (!f) {
			perror(argv[i]);
			exit(1);
		}
		while ((c = fgetc(f)) != EOF) {
			if (putchar(c) < 0) exit(1);
		}
		fclose(f);
	}
	exit(0);
}
