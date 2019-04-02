#include <stdio.h>

void fact(int);

int main() {
    int num;
    printf("팩토리얼(!) 계산을 하는 프로그램 입니다.\n");
    printf("숫자를 입력해 주세요 : ");
    scanf("%d", &num);
    fact(num);
    return 0;
}
