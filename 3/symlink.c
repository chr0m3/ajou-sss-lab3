/* ------------------------------------------------------------
 * 파일: symlink.c
 * 기능: 심볼릭링크 생성.
 * 개발자: 201720701 강준구
 * 날짜: 1차 개발: 2019년 4월 2일
 * ------------------------------------------------------------ */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
    if(symlink(argv[1], argv[2]) == -1) {
        printf("symlink failed");
        exit(1);
    }

    exit(0);
}
