#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/*

Осуществить запись и считывание структур из файла.
Все делать через пользовательские функции.
Размер main не больше 30 строк, пользовательских функций не больше 50 строк кода.
Массив структур должен быть динамическим

Студент: фамилия, имя, отчество; домашний адрес; группа; рейтинг.
1)	Ввод массива структур;
2)	Вывод на экран массива структур;
3)	Изменение заданной структуры;
4)	Поиск в массиве структур по заданному параметру;
5)	Сортировка массива структур по заданному параметру;
6)	Поиск в массиве структур по заданному параметру
7)	Удаление структуры из массива по заданному параметру;
8)	Поиск в массиве структур по частичному совпадению заданного параметра;
*/

struct student
{
	char firstName[30];
	char lastName[30];
	char middleName[30];
	char address[30];
	char group[10];
	char rate[5];
} s;

int test(char ch)
{
	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	for (unsigned int i = 0; i < 10; i++)
	{
		if (numbers[i] == ch)
		{
			return (int)((char)ch - '0');
		}
	}
	return -1;
}

void clearScreen()
{
	if (system("CLS")) system("clear");
}

int getNumber()
{
	printf("1) Add student\n");
	printf("2) Show students\n");
	printf("3) Edit student\n");
	printf("4) Search student\n");
	printf("5) Sort students\n");
	printf("6) Delete student\n");
	printf("0) Exit\n");
	printf("Please enter choice:");
	return test(_getch());
}

student fillStudent()
{
	student stud;
	printf("Enter first name: ");
	scanf("%s", stud.firstName);
	printf("Enter last name: ");
	scanf("%s", stud.lastName);
	printf("Enter middle name: ");
	scanf("%s", stud.middleName);
	printf("Enter address: ");
	scanf("%s", stud.address);
	printf("Enter group: ");
	scanf("%s", stud.group);
	printf("Enter rate: ");
	scanf("%s", stud.rate);
	return stud;
}

int calcFileStructs(FILE* file)
{
	fseek(file, 0, 2);
	int n = ftell(file) / sizeof(student);
	rewind(file);
	return n;
}

FILE* openFile(char* mode)
{
	FILE* f = NULL;
	if (!(f = fopen("students", mode)))
	{
		printf("Error while file creating\n");
	}
	return f;
}

student* readFile(FILE* file, int size)
{
	student* list = NULL;
	if (size > 0)
	{
		list = (student *)malloc(size * sizeof(student));
		for (int i = 0; i < size; i++)
		{
			fread(&s, sizeof(student), 1, file);
			list[i] = s;
		}
		rewind(file);
	}
	return list;
}

int showStudents()
{
	FILE* file;
	if (file = openFile("rb"))
	{
		int size = calcFileStructs(file);
		student* list = readFile(file, size);
		for (int i = 0; i < size; i++)
		{
			printf("%d) %s %s %s %s %.10s %.5s\n", i + 1, list[i].lastName, list[i].firstName, list[i].middleName, list[i].address, list[i].group, list[i].rate);
		}
		fclose(file);
	}
	return 1;
}

int editStudent()
{
	showStudents();
	printf("Select student: ");
	int n = getNumber();

	return 0;
}

int deleteStudent()
{
	return 0;
}

int searchStudent()
{
	return 0;
}

int sortStudents()
{
	return 0;
}

int addStudent()
{
	if (FILE* file = openFile("ab"))
	{
		fwrite(&fillStudent(), 1, sizeof(student), file);
		fclose(file);
		return 1;
	}
	return 0;
}

int main()
{
start:
	clearScreen();
	int choice = getNumber();
	clearScreen();
	switch (choice)
	{
	case 0:
		printf("Good bye!\n");
		system("pause");
		break;
	case 1:
		addStudent();
		goto start;
	case 2:
		showStudents();
		system("pause");
		goto start;
	case 3:
		editStudent();
		goto start;
	case 4:
		searchStudent();
		goto start;
	case 5:
		sortStudents();
		goto start;
	case 6:
		deleteStudent();
		goto start;
	default:
		printf("Please enter from 0 to 6\n");
		system("pause");
		goto start;
	}
	return 0;
}