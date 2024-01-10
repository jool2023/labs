
#include <stdio.h>
#include <math.h>

int main()
{
      int N, array[10] = { 0 };
int result;
float c, sum = 0.0;

scanf("%d", &N);

for (int i = 0; i < N; i++)

    scanf("%d", &array[i]);


for (int i = 0; i < N; i++)
{
    sum = sum + array[i];
}
sum = sum / N;

c = fabs(sum - array[0]);
result = array[0];

for (int i = 1; i < N; i++)
{
    if (fabs(sum - array[i]) < c)
    {
        c = fabs(sum - array[i]);
        result = array[i];
    }
}

printf("%d", result);
}