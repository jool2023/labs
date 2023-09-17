#include <stdio.h>

int main() {
    int n, factorial = 1;
	scanf("%d", &n);
	for(int i=n; i >= 2; i=i-2){
	    factorial = factorial * i;
	}
	printf("Двойной факториал  = %d", factorial);
}