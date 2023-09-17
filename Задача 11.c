#include <stdio.h>

int main() {
    int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
    if (a == b && a == c && b == c){
        printf("все числа равны %d", a);
    } else if(a >= b && a >= c){
        printf("Наибольшее число: %d", a);
    } else if(c >= b && c >= b){
        printf("Наибольшее число: %d", c);
    } else if(b >= a && b >= c){
        printf("Наибольшее число: %d", b);
    }
}