#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateTree(struct Node* root, int data) {
    if (root == NULL) {
        root = (struct Node*)malloc(sizeof(struct Node));
        if (root == NULL) {
            printf("Ошибка выделения памяти");
            exit(0);
        }
        root->left = NULL;
        root->right = NULL;
        root->data = data;
    }
    else {
        if (data > root->data) {
            root->right = CreateTree(root->right, data);
        }
        else {
            root->left = CreateTree(root->left, data);
        }
    }
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

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

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
        scanf("%d", &D);
        if (D == -1) {
            printf("Построение дерева окончено\n\n");
            start = 0;
        }
        else {
            root = CreateTree(root, D);  
        }
    }

    print_tree(root, 0);

    printf("Введите число для поиска: ");
    scanf("%d", &D); 
    struct Node* found = search(root, D);
    if (found) {
        printf("Число %d найдено в дереве\n", D);
    }
    else {
        printf("Число %d не найдено\n", D);
    }

    printf("Введите число для подсчёта вхождений: ");
    scanf("%d", &D); 
    int count = count_occurrences(root, D);
    printf("Число %d встречается %d раз(а) в дереве\n", D, count);

    return 0;
}