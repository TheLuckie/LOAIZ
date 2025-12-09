#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(void)
{
    setlocale(LC_ALL, "rus");
    int temp, n = 10, i = 0, max_a = 0, min_a = 10000;


    int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

    while (i < n / 2)
    {
        temp = a[i];
        a[i] = a[9 - i];
        a[9 - i] = temp;
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
