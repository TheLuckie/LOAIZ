#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int** G;
int* NUM;
int size_G;

int* queue;
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

void allocateMemory() {
    G = (int**)malloc(size_G * sizeof(int*));
    for (int i = 0; i < size_G; i++) {
        G[i] = (int*)malloc(size_G * sizeof(int));
    }

    NUM = (int*)malloc(size_G * sizeof(int));

    queue = (int*)malloc(size_G * sizeof(int));
}

void freeMemory() {
    for (int i = 0; i < size_G; i++) {
        free(G[i]);
    }
    free(G);
    free(NUM);
    free(queue);
}

void generateMatrix() {
    srand(time(NULL));

    for (int i = 0; i < size_G; i++) {
        for (int j = 0; j < size_G; j++) {
            G[i][j] = 0;
        }
    }

    for (int i = 0; i < size_G; i++) {
        for (int j = i + 1; j < size_G; j++) {
            int edge = rand() % 2;
            G[i][j] = edge;
            G[j][i] = edge;
        }
    }
}

void printMatrix(FILE* file) {
    printf("Сгенерированная матрица смежности (%dx%d):\n", size_G, size_G);
    fprintf(file, "Сгенерированная матрица смежности (%dx%d):\n", size_G, size_G);

    for (int i = 0; i < size_G; i++) {
        for (int j = 0; j < size_G; j++) {
            printf("%d ", G[i][j]);
            fprintf(file, "%d ", G[i][j]);
        }
        printf("\n");
        fprintf(file, "\n");
    }
}

void BFS(int v, FILE* file) {
    enqueue(v);
    NUM[v] = 1;

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);
        fprintf(file, "%d ", current);

        for (int i = 0; i < size_G; i++) {
            if (G[current][i] == 1 && NUM[i] == 0) {
                enqueue(i);
                NUM[i] = 1;
            }
        }
    }
}

void POSH(FILE* file) {
    front = 0;
    rear = 0;

    for (int i = 0; i < size_G; i++) {
        NUM[i] = 0;
    }

    printf("Обход в ширину (BFS): ");
    fprintf(file, "Обход в ширину (BFS): ");

    for (int v = 0; v < size_G; v++) {
        if (NUM[v] == 0) {
            BFS(v, file);
        }
    }
    printf("\n");
    fprintf(file, "\n");
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    printf("Введите размер графа: ");
    scanf("%d", &size_G);

    if (size_G <= 0) {
        printf("Размер графа должен быть положительным числом!\n");
        return 1;
    }

    allocateMemory();

    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        freeMemory();
        return 1;
    }

    generateMatrix();
    printMatrix(file);
    POSH(file);
    fclose(file);
    freeMemory();
    printf("\nРезультаты записаны в файл output.txt\n");

    return 0;
}