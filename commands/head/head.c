#include <stdio.h>
#include <stdlib.h>

static void do_head(FILE *stream, int lines_count);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(1);
    }

    int lines_count = atoi(argv[1]);
    if (lines_count < 1) {
        fprintf(stderr, "Wrong argument: %s\n", argv[1]);
        exit(1);
    }

    if (argc == 2) {
        do_head(stdin, lines_count);
    } else {
        int i;

        for(i = 2; i < argc; i++) {
            FILE *f;

            if ((f = fopen(argv[i], "r")) < 0) {
                perror(argv[i]);
                exit(1);
            }

            do_head(f, lines_count);

            if (fclose(f) < 0) {
                perror(argv[i]);
                exit(1);
            }
        }
    }

    exit(0);
}

static void do_head(FILE *stream, int lines_count) {
    int c;

    while ((c = getc(stream)) != EOF) {
        if (putchar(c) < 0) exit(1);
        if (c == '\n') {
            lines_count--;
            if (lines_count == 0) return;
        }
    }
}
