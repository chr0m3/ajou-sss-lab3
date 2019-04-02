#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
    if(unlink(argv[1]) == -1) {
        printf("unlink failed");
        exit(1);
    }

    return 0;
}
