#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(void)
{
    setlocale(LC_ALL, "rus");

    int rows, cols;

    printf("Введите количество строк: ");
    scanf("%d", &rows);

    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    int** array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }

    srand(time(NULL));

    printf("Сгенерированный массив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 100;
            printf("%-2d ", array[i][j]);
        }
        printf("\n");
    }

    printf("\nСуммы строк:\n");
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += array[i][j];
        }
        printf("Строка %d: %d\n", i + 1, rowSum);
    }

    printf("\nСуммы столбцов:\n");
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += array[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, colSum);
    }

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

