#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateTree(struct Node* root, struct Node* r, int data) {
    if (r == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        if (r == NULL) {
            printf("Ошибка выделения памяти");
            exit(0);
        }
        r->left = NULL;
        r->right = NULL;
        r->data = data;
        if (root == NULL) return r;
        if (data > root->data)
            root->left = r;
        else
            root->right = r;
        return r;
    }
    if (data > r->data)
        CreateTree(r, r->left, data);
    else
        CreateTree(r, r->right, data);
    return root;
}

void print_tree(struct Node* r, int l) {
    if (r == NULL) {
        return;
    }
    print_tree(r->right, l + 1);
    for (int i = 0; i < l; i++) {
        printf(" ");
    }
    printf("%d\n", r->data);
    print_tree(r->left, l + 1);
}

// Поиск значения в дереве
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Подсчёт числа вхождений элемента
int count_occurrences(struct Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    int count = (root->data == value) ? 1 : 0;
    return count + count_occurrences(root->left, value) + count_occurrences(root->right, value);
}

int main() {
    setlocale(LC_ALL, "");
    struct Node* root = NULL;
    int D, start = 1;

    printf("-1 - окончание построения дерева\n");
    while (start) {
        printf("Введите число: ");
        scanf("%d", &D); // Используем scanf вместо scanf_s
        if (D == -1) {
            printf("Построение дерева окончено\n\n");
            start = 0;
        } else {
            root = CreateTree(root, root, D);
        }
    }

    print_tree(root, 0);

    printf("Введите число для поиска: ");
    scanf("%d", &D); // Используем scanf вместо scanf_s
    struct Node* found = search(root, D);
    if (found) {
        printf("Число %d найдено в дереве\n", D);
    } else {
        printf("Число %d не найдено\n", D);
    }

    printf("Введите число для подсчёта вхождений: ");
    scanf("%d", &D); // Используем scanf вместо scanf_s
    int count = count_occurrences(root, D);
    printf("Число %d встречается %d раз(а) в дереве\n", D, count);

    return 0;
}
