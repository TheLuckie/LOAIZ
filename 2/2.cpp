#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <StdAfx.h>

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start = clock(); // объявляем переменные для определения времени выполнения

	int i=0, j=0, r;
	int a[1000][1000], b[1000][1000], c[1000][1000], elem_c;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while(i<1000)
	{
		while(j<1000)
		{
			a[i][j]=rand()% 1000 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i=0; j=0;
	while(i<1000)
	{
		while(j<1000)
		{
			b[i][j]=rand()% 1000 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}

	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			elem_c=0;
			for(r=0;r<1000;r++)
			{
				elem_c=elem_c+a[i][r]*b[r][j];
				c[i][j]=elem_c;
			}
		}
	}
	clock_t end = clock();
	float cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
	printf("Для выполнения цикла for потребовалось %f секунды \n", cpu_time_used);


	return(0);
}

