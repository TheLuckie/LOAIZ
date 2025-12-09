#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(void)
{
    setlocale(LC_ALL, "rus");

    int n; // Размер массива
    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Размер массива должен быть больше нуля!\n");
        return 1;
    }

    int* a = (int*)malloc(n * sizeof(int));

    srand(time(NULL));
    printf("Сгенерированный массив: ");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    free(a);
    return 0;
}
