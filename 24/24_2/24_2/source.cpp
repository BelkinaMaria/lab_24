#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
#include <Windows.h>

void num1(int n) {

	printf("%d ", n);

	if (n > 1) {
		num1(n - 2);
	}
}

void num2(int n) {

	if (n > 1) {
		num2(n - 2);
	}

	printf("%d ", n);
}

void num3(int n) {

	printf("%d ", n);

	if (n > 1) {
		num3(n - 2);
	}

	printf("%d ", n);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n\n");
		printf("Выберите номер:\n");
		printf("1: Задача 2.1.\n");
		printf("2: Задача 2.2.\n");
		printf("3: Задача 2.3.\n");
		printf("\n");
		printf("0: Выход.\n");

		scanf_s("%d", &item);

		switch (item)
		{
		case 1:
		{
			printf("n = ");
			int n;
			scanf_s("%d", &n);

			num1(n);
			break;
		}

		case 2:
		{
			printf("n = ");
			int n;
			scanf_s("%d", &n);

			num2(n);
			break;
		}

		case 3:
		{
			printf("n = ");
			int n;
			scanf_s("%d", &n);

			num3(n);
			break;
		}
		}

	} while (item != 0);
}