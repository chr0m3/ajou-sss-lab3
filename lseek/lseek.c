#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";


int main(void) {
    int fd;

    fd = creat("file.hole", (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
    write(fd, buf1, 10);
    lseek(fd, 14, SEEK_CUR);
    write(fd, buf2, 10);
    exit(0);
}
