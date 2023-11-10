�1 ����������� �������, ������� ���������� ��������� ���������� ������� ��������� �������.

#include <stdio.h>
#include <stdlib.h>

// ������� ��� �������� � ���������� ��������� �������
double** createIdentityMatrix(int size) {
    // ��������� ������ ��� ��������� ������ (�������)
    double** matrix = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (double*)malloc(size * sizeof(double));
    }

    // ���������� ������� ����������
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                matrix[i][j] = 1.0; // ������� ��������� - �������
            } else {
                matrix[i][j] = 0.0; // ��������� �������� - ����
            }
        }
    }

    return matrix;
}

int main() {
    int size = 3; // ������ ������ ���������� �������

    // �������� ������� ��� �������� ��������� �������
    double** identityMatrix = createIdentityMatrix(size);

    // ������� ������� �� �����
    printf("��������� ������� %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%f ", identityMatrix[i][j]);
        }
        printf("\n");
    }

    // ����������� ���������� ������
    for (int i = 0; i < size; i++) {
        free(identityMatrix[i]);
    }
    free(identityMatrix);

    return 0;
}


�3	����������� �������, ������� �� ���� �������� ���������� ������ � ��������� ����������. ������� ���������� ������ ��� �� �����������, � ���������������
� ����������� �� ��������� ���������� (true � �� �����������, false � �� ��������)
#include <stdio.h>
#include <stdbool.h>

// ������� ��� ��������� ��������� ��� ����������
int compare(const void *a, const void *b) {
    int intA = *((int*)a);
    int intB = *((int*)b);

    return intA - intB;
}

// ������� ��� ���������� ������� � ����������� �� ��������� ����������
int* sortArray(int* arr, int size, bool ascending) {
    // ������� ����� ��������� �������
    int* sortedArr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }

    // ���������� ����������� ������� qsort ��� ����������
    if (ascending) {
        qsort(sortedArr, size, sizeof(int), compare);
    } else {
        qsort(sortedArr, size, sizeof(int), compare);
        // ����������� ������ ��� ��������� ����������
        int temp;
        for (int i = 0; i < size / 2; i++) {
            temp = sortedArr[i];
            sortedArr[i] = sortedArr[size - 1 - i];
            sortedArr[size - 1 - i] = temp;
        }
    }

    return sortedArr;
}

int main() {
    int size = 5;
    int arr[] = {3, 1, 4, 1, 5};
    bool ascending = true;

    int* sortedArr = sortArray(arr, size, ascending);

    printf("��������������� ������:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    // ����������� ������ ����� �������������
    free(sortedArr);

    return 0;
}



�4 ���� ����������� ����� n. �������� ��� ����� �� 1 �� n. ����������� ��� ������ ��������.
#include <stdio.h>

// ������� ��� ������ ����� �� 1 �� n � �������������� ��������
void printNumbers(int n) {
    if (n > 0) {
        printNumbers(n - 1); // ����������� ����� ��� ����� n-1
        printf("%d ", n);    // ����� ����� n ����� ��������
    }
}

int main() {
    int n;

    printf("������� ����������� ����� n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("����� ������ ���� �����������.\n");
    } else {
        printf("����� �� 1 �� %d: ", n);
        printNumbers(n);
        printf("\n");
    }

    return 0;
}


�5 �������� �������, ������� ���������, ������ �� � ���������� ������ �������� ������� ��� ���. ����������� ������� � �������� �����
��� ������� ���� ������. �������� ����� ���������� ����� ������� ��� ������� �������� (��������, 100000000 ���������). ����������� ��� ������ ��������

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ������� ��� �������� ��������� � �������
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // ������ �������, ���������� ������
        }
    }
    return -1; // ������� �� ������
}

// ������� ��� ��������� ������ �������� � ��������������� �������
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // ������ �������, ���������� ������
        }

        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target); // ����������� ����� � ����� ��������
        }

        return binarySearch(arr, mid + 1, right, target); // ����������� ����� � ������ ��������
    }

    return -1; // ������� �� ������
}

int main() {
    const int size = 100000000; // ������ �������
    int* arr = (int*)malloc(size * sizeof(int));

    // ��������� ������ ���������� ������� � ��������� ���
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    int target = size - 1; // �������, ������� ����� ������

    // �������� ����� ���������� ��������� ������
    clock_t start = clock();
    int linearResult = linearSearch(arr, size, target);
    clock_t end = clock();
    double linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    // �������� ����� ���������� ��������� ������
    start = clock();
    int binaryResult = binarySearch(arr, 0, size - 1, target);
    end = clock();
    double binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (linearResult != -1) {
        printf("�������� �����: ������� %d ������ �� ������� %d, ����� ����������: %f ���\n", target, linearResult, linearTime);
    } else {
        printf("�������� �����: ������� %d �� ������, ����� ����������: %f ���\n", target, linearTime);
    }

    if (binaryResult != -1) {
        printf("�������� �����: ������� %d ������ �� ������� %d, ����� ����������: %f ���\n", target, binaryResult, binaryTime);
    } else {
        printf("�������� �����: ������� %d �� ������, ����� ����������: %f ���\n", target, binaryTime);
    }

    free(arr);

    return 0;
}


�6.	������� ������ ��������� cos x5 + x4-345.3*x-23=0 �� ������� [0;10] � ��������� �� x �� ���� 0.001.
��������, ��� �� ���� ���������� ������ ������������. ����������� ��� ����� ����� ������� ������� ������� (� ��������).

#include <stdio.h>
#include <math.h>

// ������� ��� ���������� �������� ���������
double equation(double x) {
    return cos(pow(x, 5)) + pow(x, 4) - 345.3 * x - 23;
}

// ������� ��� ���������� ����� ��������� ������� ������� ������� �������
double findRoot(double a, double b, double tolerance) {
    double c = (a + b) / 2.0; // �������� �������
    double fc = equation(c); // �������� ������� � ����� c

    // ���� ������� ����� a � b ������ �������� ��������, ���������� c
    if (fabs(b - a) < tolerance) {
        return c;
    }

    // ���� ������� � c ������ � ����, ���������� c
    if (fabs(fc) < tolerance) {
        return c;
    }

    // ���� ������� � ����� a � c ����� ������ �����, ���� ������ � ����� ��������
    if (equation(a) * fc < 0) {
        return findRoot(a, c, tolerance);
    }

    // � ��������� ������ ���� ������ � ������ ��������
    return findRoot(c, b, tolerance);
}

int main() {
    double a = 0.0; // ����� ������� �������
    double b = 10.0; // ������ ������� �������
    double tolerance = 0.001; // ��������

    // �������� ������� ��� ���������� ����� ���������
    double root = findRoot(a, b, tolerance);

    printf("������ ���������: %lf\n", root);

    return 0;
}


�7	����� �������, �������� ������� � �������� �������� ���� ��������� �������.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ������� ��� ���������� ��������, �������� �������� � �������� ��������
int findClosestToAverage(int arr[], int size) {
    if (size <= 0) {
        return -1; // ���������� -1 � ������ ������� �������
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    double average = (double)sum / size; // ������� ��������

    int closest = arr[0]; // �������� � ������� ��������
    int minDifference = abs(arr[0] - average);

    for (int i = 1; i < size; i++) {
        int difference = abs(arr[i] - average);
        if (difference < minDifference) {
            closest = arr[i];
            minDifference = difference;
        }
    }

    return closest;
}

int main() {
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("������ ������� ������ ���� �������������.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("������ ��������� ������.\n");
        return 1;
    }

    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int closest = findClosestToAverage(arr, size);

    if (closest != -1) {
        printf("�������, �������� ������� � �������� ��������: %d\n", closest);
    } else {
        printf("������ ����.\n");
    }

    free(arr);

    return 0;
}


�8	����������, ������� �� � ������� ���������� ��������.
#include <stdio.h>

// ������� ��� ����������� ������� ���������� ��������� � �������
int hasDuplicates(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 1; // ���� ������������� ��������
            }
        }
    }
    return 0; // ��� ������������� ���������
}

int main() {
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("������ ������� ������ ���� �������������.\n");
        return 1;
    }

    int arr[size];

    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    if (hasDuplicates(arr, size)) {
        printf("� ������� ���� ������������� ��������.\n");
    } else {
        printf("� ������� ��� ������������� ���������.\n");
    }

    return 0;
}


�9	� ������� ����� �������� ����������� ������������������. ��������� ���������, ������ ������, ����� ����� �����. ����� ���������� ����� ���������.
#include <stdio.h>

int main() {
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("������ ������� ������ ���� �������������.\n");
        return 1;
    }

    int arr[size];

    printf("������� �������� ������� (����������� ������������������):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 1; // �������� � 1 �������� (������ �������)
    int duplicates = 0; // ������� ���������� ���������

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        } else {
            if (count > 1) {
                duplicates++;
            }
            count = 1; // ���������� �������
        }
    }

    // ��������� ��������� ��������
    if (count > 1) {
        duplicates++;
    }

    printf("���������� ���������, ������ ����� ����� � ������ ������: %d\n", duplicates);

    return 0;
}


�10	�������� ���� � ������������� �� ������ �������� �������.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("������ ������� ������ ���� �������������.\n");
        return 1;
    }

    int arr[size];

    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // ������� ������������ �� ������ ������� � ��� ������
    int maxAbsValue = abs(arr[0]);
    int maxAbsIndex = 0;

    for (int i = 1; i < size; i++) {
        int absValue = abs(arr[i]);
        if (absValue > maxAbsValue) {
            maxAbsValue = absValue;
            maxAbsIndex = i;
        }
    }

    // �������� ���� ������������� �� ������ ��������
    arr[maxAbsIndex] = -arr[maxAbsIndex];

    printf("������ � ���������� ������ � ������������� �� ������ ��������:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

�11	���� ��� �������. �������� ������� �� �������� ����������� �� ����������. ���������� �������� ���� ���� �������� � ������ ������ ���, ����� ��� ����� ��������� �������������� �� ����������.
#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0; // ������� ������� � ������ �������
    int j = 0; // ������� ������� �� ������ �������
    int k = 0; // ������� ������� � ������� �������

    // ���������� ���������� �������� �� ��� ���, ���� �� ���������� ��� �������� �������
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // ���� ������ ������ �� ����������, ��������� ���������� ��������
    while (i < size1) {
        result[k++] = arr1[i++];
    }

    // ���� ������ ������ �� ����������, ��������� ���������� ��������
    while (j < size2) {
        result[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    printf("������� ������ ������� �������: ");
    scanf("%d", &size1);
    int arr1[size1];

    printf("������� �������� ������� ������� (������������� �� ����������):\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("������� ������ ������� �������: ");
    scanf("%d", &size2);
    int arr2[size2];

    printf("������� �������� ������� ������� (������������� �� ����������):\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int result[size1 + size2]; // ��������� ����������� ��������
    mergeArrays(arr1, size1, arr2, size2, result);

    printf("��������� ����������� �������� (������������� �� ����������):\n");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}


�13 ����� ����� ��������� �������, ������������� ����� ������������ � ����������� ���������� (������������).
#include <stdio.h>

int main() {
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("������ ������� ������ ���� �������������.\n");
        return 1;
    }

    int arr[size];

    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // ������� ������������ � ����������� �������� � �� �������
    int maxElement = arr[0];
    int minElement = arr[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }

    // ���������� ��������� � �������� ������� ��� ������������
    int start = (maxIndex < minIndex) ? maxIndex : minIndex;
    int end = (maxIndex > minIndex) ? maxIndex : minIndex;

    int sum = 0;

    // ��������� �������� ����� ������������ � �����������
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }

    printf("����� ��������� ����� ������������ � ����������� ����������: %d\n", sum);

    return 0;
}


�15	�������� ������� ���������� �������� �� ��� ������� �����.
#include <stdio.h>

int main() {
    int size;
    printf("������� ������ �������: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("������ ������� ������ ���� �������������.\n");
        return 1;
    }

    int arr[size];

    printf("������� �������� �������:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    if (size < 2) {
        printf("������������ ��������� ��� ������.\n");
        return 1;
    }

    // ��������� ������ ��� �������� �� ��������� ����������
    int temp1 = arr[0];
    int temp2 = arr[1];

    // ���������� ��������� �������� �� ��� ������� �����
    for (int i = 2; i < size; i++) {
        arr[i - 2] = arr[i];
    }

    // �������� ��������� ���������� � ����� �������
    arr[size - 2] = temp1;
    arr[size - 1] = temp2;

    printf("������ ����� ������������ ������ �� ��� ������� �����:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
