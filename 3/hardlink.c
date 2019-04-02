/* ------------------------------------------------------------
 * 파일: hardlink.c
 * 기능: 하드링크 생성.
 * 개발자: 201720701 강준구
 * 날짜: 1차 개발: 2019년 4월 2일
 * ------------------------------------------------------------ */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
    if(link(argv[1], argv[2]) == -1) {
        printf("link failed");
        exit(1);
    }

    return 0;
}
