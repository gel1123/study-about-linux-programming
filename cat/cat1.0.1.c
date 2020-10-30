#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static void do_cat(const char *path);
static void rwstd();
static void die(const char *s);

int
main(int argc, char *argv[])
{
	int i;

	if (argc < 2) {
		rwstd();
	}
	for (i = 1; i < argc; i++) {
		do_cat(argv[i]);
	}
	exit(0);
}

#define BUFFER_SIZE 2048

static void
do_cat(const char *path)
{
	int fd;
	unsigned char buf[BUFFER_SIZE];
	int n;

	fd = open(path, O_RDONLY);
	if (fd < 0) die(path);
	for (;;) {
		n = read(fd, buf, sizeof buf);
		if (n < 0) die(path);
		if (n == 0) break;
		if (write(STDOUT_FILENO, buf, n) < 0) die(path);
	}
	if (close(fd) < 0) die(path);
}

static void
rwstd()
{
	unsigned char buf[BUFFER_SIZE];
	int n;
	int i;
#if 0
	fcntl(0, F_SETFL, O_NONBLOCK);
	fcntl(1, F_SETFL, O_NONBLOCK);
#endif	
	i = 6;
	while ((i = i-1) > 0) {
		printf("i: %d\n", i);
		n = read(0, buf, sizeof buf);
		printf("n: %d\n", n);
		printf("errno: %d\n", errno);
		if (write(STDOUT_FILENO, buf, n) < 0) exit(1);
	}
}

static void
die(const char *s)
{
	perror(s);
	exit(1);
}
