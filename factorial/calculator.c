#include <stdio.h>

void fact(int n) {
    int sum = 1;
    for(int i = 1; i <= n; i++) sum *= i;
    printf("%d의 팩토리얼은 %d입니다.\n", n, sum);
}
