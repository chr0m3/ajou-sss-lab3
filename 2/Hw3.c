/* ------------------------------------------------------------
 * 파일: Hw3.c
 * 기능: 파일 생성, 파일 쓰기, 파일 읽어서 건너뛰며 출력하기.
 * 개발자: 201720701 강준구
 * 날짜: 1차 개발: 2019년 4월 2일
 * ------------------------------------------------------------ */


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>


int main(void) {
    // 1. Create file.
    int fd = creat("exam", (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
    
    // 2. Write text to file.
    int count;
    char buf[1024];

    if((count = read(1, buf, sizeof buf)) > 0) {
        if(write(fd, buf, count) != count) {
            printf("write error");
            exit(1);
        }
    }

    if(count < 0) {
        printf("read error");
        exit(1);
    }

    close(fd);  // Close file.

    fd = open("exam", O_RDONLY);

    // 3. Read text from file(1).
    lseek(fd, 0, SEEK_SET);  // Move to start of the file.
    while((count = read(fd, buf, 1)) == 1) {
        if(write(0, buf, 1) != 1) {
            printf("write error");
            exit(1);
        }
        if(lseek(fd, 1, SEEK_CUR) == -1) break;  // Jump.
    }

    if(count < 0) {
        printf("read error");
        exit(1);
    }

    // 4. Read text from file(2).
    lseek(fd, -2, SEEK_END);  // Move to end of the file.
    while((count = read(fd, buf, 1)) == 1) {
        if(write(0, buf, 1) != 1) {
            printf("write error");
            exit(1);
        }
        if(lseek(fd, -4, SEEK_CUR) == -1) break;  // Jump.
    }

    if(count < 0) {
        printf("read error");
        exit(1);
    }


    return 0;
}
