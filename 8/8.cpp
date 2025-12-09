#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define SIZE 100

int G[SIZE][SIZE];
int NUM[SIZE];
int size_G;

int queue[SIZE];
int front = 0, rear = 0;

void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

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

void printMatrix() {
    printf("Сгенерированная матрица смежности:\n");
    for (int i = 0; i < size_G; i++) {
        for (int j = 0; j < size_G; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void BFS(int v) {
    enqueue(v);
    NUM[v] = 1;

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < size_G; i++) {
            if (G[current][i] == 1 && NUM[i] == 0) {
                enqueue(i);
                NUM[i] = 1;
            }
        }
    }
}

void POSH() {
    for (int i = 0; i < size_G; i++) {
        NUM[i] = 0;
    }

    for (int v = 0; v < size_G; v++) {
        if (NUM[v] == 0) {
            BFS(v);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    size_G = 9;
    generateMatrix();
    printMatrix();

    printf("Обход в ширину (BFS): ");
    POSH();
    printf("\n");

    return 0;
}
