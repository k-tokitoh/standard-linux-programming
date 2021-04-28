#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static void do_cat(const char *path);
static void die(const char *s);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "%s: file name not give.\n", argv[0]);
        exit(1);
    }
    
    for (int i = 1; i < argc; i++) {
        do_cat(argv[i]);
    }
  
    exit(0);
}

static void do_cat(const char *path) {
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0) die(path);

    char buf[1024];
    int read_ret;

    for(;;) {
        read_ret = read(fd, buf, sizeof buf);
        if (read_ret < 0) die(path);
        if (read_ret == 0) break;
        if (write(STDOUT_FILENO, buf, read_ret) < 0 ) die(path);
    }

    if (close(fd) < 0) die(path);
}

static void die(const char *s) {
    perror(s);
    exit(1);
}
