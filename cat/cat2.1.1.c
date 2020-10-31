/**
 * @file wc1.0.0.c
 * @brief repoduce "cat" on fread & fwrite *incomplete
 * @author gel1123
 * @date 2020-10-31
 */

#include <stdio.h>
#include <stdlib.h>

static void do_cat(FILE *f);

int
main(int argc, char *argv[])
{
	if (argc < 2) {
		do_cat(stdin);
	} else {
		for (int i=i; i<argc; i++) {
			FILE *f = fopen(argv[i], "r");
			if (!f) exit(1);
			do_cat(f);
			fclose(f);
		}
	}
}

#define BUF_SIZE 2048

static void
do_cat(FILE *f) {
	unsigned char buf[BUF_SIZE];

	for (;;) {
		size_t n_read = fread(buf, 1, sizeof buf, f);
		if (ferror(f)) exit(1);
		size_t n_written = fwrite(buf, 1, n_read, stdout);
		if (n_read > n_written) exit(2);
		if (sizeof buf > n_read) break;
	}
}
