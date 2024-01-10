#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, max_idx;

    int temp;

    for (i = n - 1; i > 0; i--) {
        max_idx = i;
        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[max_idx]) {
                max_idx = j;
            }
        }

        temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите элементы массива: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}