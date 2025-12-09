#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int main(void)
{
    setlocale(LC_ALL, "rus");
    int i = 0, n = 10, max_a = 0, min_a = 10000;


    int a[10];

    srand(time(NULL));

    while (i < n) {
        a[i] = rand() % 100;
        i++;
    }

    i = 0;

    while (i < n) {
        if (a[i] > max_a) {
            max_a = a[i];
        }
        if (a[i] < min_a) {
            min_a = a[i];
        }
        i++;
    }
    i = 0;

    while(i<n) printf(" %d",a[i++]);

    printf("\n Разница максимального и минимального элементов: %d \n", max_a - min_a);
}
