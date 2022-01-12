#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
#include <ctype.h>
#define Path

void writeString(char* String) {
	system("cls");
	FILE* fp;
	system("cls");
	if ((fp = fopen("d:\\Work\\test23.txt", "w")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	printf("Enter the string:\n");
	while (getchar() != '\n');
	gets_s(String,100);
	fputs(String, fp);
	printf("Written to file \n");
	fclose(fp);
	_getch();
}

void readString(char* String) {
	FILE* fp;
	system("cls");
	if ((fp = fopen("d:\\Work\\test23.txt", "r+")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	printf("Text file content:\n");
	while (getchar() != '\n');
	while (fgets(String, 100, fp) != NULL) {
		printf("%s", String);
	}
	fclose(fp);
	_getch();
}

void encryptString() {
	FILE* fp;
	system("cls");
	fflush(stdin);
	char* strOne = new char[100];
	char* strTwo = new char[100];

	if ((fp = fopen("d:\\Work\\test23.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}

	fgets(strOne, 100, fp);
	fclose(fp);
	int j = 0;

	for (int i = 0; i < strlen(strOne); i++) {
		
		if (*(strOne + i) == 'Z' || *(strOne + i) == 'z') {
			*(strTwo + j) = 'A'  + (*(strOne + i)) - 'Z';
			*(strTwo + j) = 'a' + (*(strOne + i)) - 'z';
		}
		else {
			*(strTwo + j) = *(strOne + i) + 1;
		}
		j++;
	}
	
	*(strTwo + j) = '\0';

	printf_s("zashifr stroka:\n");

	if ((fp = fopen("d:\\Work\\test23.txt", "w")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	fputs(strTwo, fp);
	fclose(fp);
	_getch();
}

void decipherString() {
	FILE* fp;
	system("cls");
	fflush(stdin);
	char* strThree = new char[100];
	char* strFour = new char[100];

	if ((fp = fopen("d:\\Work\\test23.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	fgets(strThree, 100, fp);
	fclose(fp);

	int j = 0;

	for (int i = 0; i < strlen(strThree); i++) {
		
		if ((*(strThree + i)) == 'A' || (*(strThree + i)) == 'a') {
			*(strFour + j) = 'Z' + (*(strThree + i)) - 'A';
			*(strFour + j) = 'z' + (*(strThree + i)) - 'a';
		}
		else {
			*(strFour + j) = *(strThree + i) - 1;
		}
		j++;
	}

	*(strFour + j) = '\0';

	printf_s ("dehifr stroka:\n");

	if ((fp = fopen("d:\\Work\\test23.txt", "w")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}

	fputs(strFour, fp);
	fclose(fp);
	_getch();
}

void main() {
	setlocale(LC_CTYPE, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	system("cls");
	fflush(stdin);
	char* String = new char[100];
	int menu = 0;
	while (true) {
		system("cls");
		puts("Выберите пункт меню:");
		puts("1-Write string to file");
		puts("2-Read string from file and print");
		puts("3-Encrypt string and write to file");
		puts("4-Decrypt string and write to file");
		puts("5-Exit");
		scanf_s("%d", &menu);
		switch (menu) {
			case 1: {
				writeString(String);
				break;
			}
			case 2: {
				readString(String);
				break;
			}
			case 3: {
				encryptString();
				break;
			}
			case 4: {
				decipherString();
				break;
			}
			case 5: {
				exit(0);
			}
			default: {
				system("cls");
				fflush(stdin);
				puts("Invalid selection, press any key to return to the menu");
				_getch();
			}
		}
	}
	_getch();
}