#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    int i;
    struct student
    {
        char famil[20];
        char name[20];
        char facult[20];
        char Nomzach[20];
    } stud[3];

    for (i = 0; i < 3; i++)
    {
        printf("Введите фамилию студента #%d: ", i + 1);
        scanf("%19s", stud[i].famil);
    }
    for (i = 0; i < 3; i++)
    {
        printf("Введите имя студента #%d: ", i + 1);
        scanf("%19s", stud[i].name);
    }
    for (i = 0; i < 3; i++)
    {
        printf("Введите название факультета студента #%d: ", i + 1);
        scanf("%19s", stud[i].facult);
    }
    for (i = 0; i < 3; i++)
    {
        printf("Введите номер зачётной книжки студента #%d: ", i + 1);
        scanf("%19s", stud[i].Nomzach);
    }

    for (i = 0; i < 3; i++)
    {
        printf("Студент %s %s обучается на факультете %s, номер зачётной книжки %s\n",
            stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
    }

    char searchFamil[20], searchName[20], searchFacult[20], searchNomzach[20];
    printf("\nВведите параметры для поиска (введите '-' для пропуска параметра):\n");

    printf("Фамилия: ");
    scanf("%19s", searchFamil);
    printf("Имя: ");
    scanf("%19s", searchName);
    printf("Факультет: ");
    scanf("%19s", searchFacult);
    printf("Номер зачётной книжки: ");
    scanf("%19s", searchNomzach);

    int found = 0;
    for (i = 0; i < 3; i++)
    {
        if ((strcmp(searchFamil, "-") == 0 || strcmp(stud[i].famil, searchFamil) == 0) &&
            (strcmp(searchName, "-") == 0 || strcmp(stud[i].name, searchName) == 0) &&
            (strcmp(searchFacult, "-") == 0 || strcmp(stud[i].facult, searchFacult) == 0) &&
            (strcmp(searchNomzach, "-") == 0 || strcmp(stud[i].Nomzach, searchNomzach) == 0))
        {
            printf("\nНайден студент: %s %s, факультет: %s, номер зачётной книжки: %s\n",
                stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
            found = 1;
        }
    }

    if (!found)
    {
        printf("\nСтудент с заданными параметрами не найден.\n");
    }

    return 0;
}
