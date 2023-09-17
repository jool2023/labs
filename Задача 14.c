#include <stdio.h>

int main() {
    int n, factorial = 1;
	scanf("%d", &n);
	while(n >= 2){
	    factorial = factorial * n;
	    n -= 2;
	}
	printf("Двойной факториал  = %d", factorial);
}