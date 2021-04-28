#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "%s: file name not give.\n", argv[0]);
        exit(1);
    }
    
    for (int i = 1; i < argc; i++) {
        FILE *file;
        file = fopen(argv[i], "r");
        
        if (!file) {
           perror(argv[i]);
           exit(1);
        }

        int c;
        while ((c = fgetc(file)) != EOF) {
            if (putchar(c) < 0) exit(1);
        }

        fclose(file);
    }
  
    exit(0);
}
