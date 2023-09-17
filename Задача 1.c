// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a, b, c;
	scanf("%d %d", &a, &b);
    printf("%d, %d\n", a , b);
    c = a;
    a = b;
    b = c;
    printf("%d, %d\n", a , b);

    a = a + b;
    b = b - a;
    b = -b;
    a = a - b;
    printf("%d, %d", a , b);
}