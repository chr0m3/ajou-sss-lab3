#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFSIZE 8192


int main(void) {
    int n;
    char buf[BUFFSIZE];

    while((n = read(1, buf, BUFFSIZE)) > 0) {
        if(write(0, buf, n) != n) {
            printf("write error");
            exit(0);
        }
    }

    if(n < 0) {
        printf("read error");
        exit(0);
    }

    exit(0);
}
