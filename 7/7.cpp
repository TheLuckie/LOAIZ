#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 100  // Максимальное количество вершин

int G[SIZE][SIZE];  // Матрица смежности
int NUM[SIZE];      // Массив пометок (0 — не посещена, 1 — посещена)
int size_G;         // Количество вершин

// Генерация симметричной матрицы смежности
void generateMatrix() {
    srand(time(NULL));  // Инициализация генератора случайных чисел

    // Обнуляем матрицу
    for (int i = 0; i < size_G; i++) {
        for (int j = 0; j < size_G; j++) {
            G[i][j] = 0;
        }
    }

    // Заполняем только верхнюю половину и дублируем вниз
    for (int i = 0; i < size_G; i++) {
        for (int j = i + 1; j < size_G; j++) {
            int edge = rand() % 2;
            G[i][j] = edge;
            G[j][i] = edge;
        }
    }
}

// Печать матрицы смежности
void printMatrix() {
    printf("Сгенерированная матрица смежности:\n");
    for (int i = 0; i < size_G; i++) {
        for (int j = 0; j < size_G; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

// Обход в глубину (DFS)
void DFS(int v) {
    NUM[v] = 1;          // Пометили как посещённую
    printf("%d ", v);    // Вывод текущей вершины

    for (int i = 0; i < size_G; i++) {
        if (G[v][i] == 1 && NUM[i] == 0) {
            DFS(i);      // Рекурсивный вызов для соседей
        }
    }
}

// Алгоритм ПОГ (обход всех компонент связности)
void POG() {
    for (int i = 0; i < size_G; i++) {
        NUM[i] = 0;  // Пометили все вершины как "не посещённые"
    }

    for (int v = 0; v < size_G; v++) {
        if (NUM[v] == 0) {
            DFS(v);  // Запускаем DFS для новой вершины
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    size_G = 5;  // Количество вершин графа (можно менять)

    generateMatrix();  // Генерация графа
    printMatrix();     // Печать матрицы

    printf("Обход в глубину (DFS): ");
    POG();             // Запуск обхода
    printf("\n");

    return 0;
}
