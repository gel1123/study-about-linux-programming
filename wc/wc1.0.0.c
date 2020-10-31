/**
 * @file wc1.0.0.c
 * @brief repoduce "wc -l" on syscall 
 * @author gel1123
 * @date 2020-10-31
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

static void wcl(int fd);

int
main(int argc, char *argv[])
{


	if (argc < 2) { // stdio case

		wcl(0);

	} else { // fileio case
		for (int i = 1; i < argc; i++) {
			char *path = argv[i];
			int fd = open(path, O_RDONLY);
			wcl(fd);
			close(fd);
		}
	}
	exit(0);
}

static void
wcl(int fd) {

	unsigned char buf[BUF_SIZE];
	int n;
	if ((n = read(fd, buf, sizeof buf)) > 0) {

		unsigned long line_num = 0;

		for (int i = 0; i < BUF_SIZE; i++) {
			if (buf[i] == '\n') {
				line_num++;
			}
		}
		printf("%lu\n", line_num);
	}
}
