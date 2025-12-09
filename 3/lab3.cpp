#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Определение структуры узла списка
struct node {
    char inf[256];     // Полезная информация
    int priority;      // Приоритет
    struct node* next; // Указатель на следующий элемент
};

// Глобальные указатели на начало и конец списка
struct node* head = NULL, * last = NULL;

// Прототипы функций
struct node* get_struct(void);
void spstore(void);
void review(void);

// Функция создания элемента списка
struct node* get_struct(void) {
    struct node* p = NULL;
    char s[256];
    int priority;

    // Выделение памяти для нового узла
    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) {
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }

    // Ввод данных
    printf("Введите название объекта: ");
    scanf("%s", s);
    if (*s == 0) {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(p->inf, s);

    printf("Введите приоритет объекта (целое число): ");
    scanf("%d", &priority);
    p->priority = priority;

    p->next = NULL;
    return p;
}

// Функция добавления элемента в список с учётом приоритета
void spstore(void) {
    struct node* p = NULL;
    struct node* current = head;
    struct node* prev = NULL;

    p = get_struct();
    if (p == NULL) return; // Если элемент не создан, выходим

    // Если список пуст, новый элемент становится головой
    if (head == NULL) {
        head = p;
        last = p;
        return;
    }

    // Поиск позиции для вставки элемента по приоритету
    while (current != NULL && current->priority >= p->priority) {
        prev = current;
        current = current->next;
    }

    // Вставка нового элемента
    if (prev == NULL) { // Вставка в начало списка
        p->next = head;
        head = p;
    }
    else { // Вставка между элементами или в конец
        prev->next = p;
        p->next = current;
        if (current == NULL) { // Если вставили в конец, обновляем last
            last = p;
        }
    }
    return;
}

// Функция просмотра содержимого списка
void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    while (struc) {
        printf("Имя - %s, Приоритет - %d\n", struc->inf, struc->priority);
        struc = struc->next;
    }
    return;
}

// Главная функция
int main(void) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);а
    int choice;

    while (1) {
        printf("\n1. Добавить элемент в список\n");
        printf("2. Просмотреть список\n");
        printf("3. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            spstore();
            break;
        case 2:
            review();
            break;
        case 3:
            return 0;
        default:
            printf("Неверный выбор, попробуйте снова.\n");
        }
    }
}
