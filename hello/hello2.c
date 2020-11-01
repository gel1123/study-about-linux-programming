/**
 * @file hello2.c
 * @brief hello world on C (syscall version.)
 * @author gel1123
 * @date 2020-10-31
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 1024

int
main(int argc, char *argv[])
{

	unsigned char buf[BUFSIZE];
	if (argc < 2) {
		char s[30] = "Hello ";
		int n = read(0, buf, sizeof buf);
		strcat(s, (char*)buf);
		write(1, s, sizeof s);
	} else {
		char a[30] = "Hello ";
		strcat(a, argv[1]);
		strcat(a, "\n");
		write(1, a, sizeof a);
	}
	return 0;
}
