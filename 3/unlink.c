/* ------------------------------------------------------------
 * 파일: unlink.c
 * 기능: 링크 삭제(unlink).
 * 개발자: 201720701 강준구
 * 날짜: 1차 개발: 2019년 4월 2일
 * ------------------------------------------------------------ */


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
