#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


int main(int argc, char* argv[]) {
    int accmode, val;

    if(argc != 2) {
        printf("usage: a.out <descriptor #>");
        exit(0);
    }

    val = fcntl(atoi(argv[1]), F_GETFL);
    accmode = val & O_ACCMODE;

    if(accmode == O_RDONLY) printf("read only");
    else if(accmode == O_WRONLY) printf("write only");
    else if(accmode == O_RDWR) printf("read write");
    else printf("unknown access mode");

    if(val & O_APPEND) printf(", append");
    if(val & O_NONBLOCK) printf(", nonblocking");

    printf("\n");

    exit(0);
}
