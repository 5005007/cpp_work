#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define datname "students.dat"

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
	char firstName[125];
	char lastName[125];
	char middleName[125];
	char address[125];
	char group[125];
	char rate[125];
};

struct students
{
	int size;
	int selected;
	student* list;
};

int compareFirstname(const void* a, const void* b)
{
	return strcmp(
		((struct student *)a)->firstName,
		((struct student *)b)->firstName
	);
}

int compareLastname(const void* a, const void* b)
{
	return strcmp(
		((struct student *)a)->lastName,
		((struct student *)b)->lastName
	);
}

int compareMiddlename(const void* a, const void* b)
{
	return strcmp(
		((struct student *)a)->lastName,
		((struct student *)b)->lastName
	);
}

int compareAddress(const void* a, const void* b)
{
	return strcmp(
		((struct student *)a)->lastName,
		((struct student *)b)->lastName
	);
}

int compareGroup(const void* a, const void* b)
{
	return strcmp(
		((struct student *)a)->lastName,
		((struct student *)b)->lastName
	);
}

int compareRate(const void* a, const void* b)
{
	return strcmp(
		((struct student *)a)->lastName,
		((struct student *)b)->lastName
	);
}

int sortStructs(struct student *structs, size_t count, size_t memberNum)
{
	switch ((memberNum - 1) * 125)
	{
	case 0:
		qsort(structs, count, sizeof *structs, compareFirstname);
		break;
	case offsetof(struct student, lastName):
		qsort(structs, count, sizeof *structs, compareLastname);
		break;
	case offsetof(struct student, middleName):
		qsort(structs, count, sizeof *structs, compareMiddlename);
		break;
	case offsetof(struct student, address):
		qsort(structs, count, sizeof *structs, compareAddress);
		break;
	case offsetof(struct student, group):
		qsort(structs, count, sizeof *structs, compareGroup);
		break;
	case offsetof(struct student, rate):
		qsort(structs, count, sizeof *structs, compareRate);
		break;
	default:
		printf("Wrong member num", memberNum);
		return 0;
	}
	return 1;
}

int test(char ch)
{
	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	for (unsigned int i = 0; i < 10; i++)
	{
		if (numbers[i] == ch)
			return (int)((char)ch - '0');
	}
	return -1;
}

void clearScreen()
{
	if (system("CLS"))
		system("clear");
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

int file_exist(char *filename)
{
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
}

FILE* openFile(char* mode)
{
	FILE* f = NULL;
	if (!(f = fopen(datname, mode)))
	{
		printf("Error while file creating\n");
	}
	return f;
}

int calcFileStructs(FILE* file)
{
	fseek(file, 0, 2);
	int size = ftell(file) / sizeof(student);
	rewind(file);
	return size;
}

students readFile()
{
	students result;
	if (FILE* file = openFile("rb"))
	{
		result.size = calcFileStructs(file);
		if (result.size > 0)
		{
			result.list = (student *)malloc(result.size * sizeof(student));
			for (int i = 0; i < result.size; i++)
			{
				student stud;
				fread(&stud, sizeof(student), 1, file);
				result.list[i] = stud;
			}
		}
		fclose(file);
	}
	return result;
}

students showStudents()
{
	students stud = readFile();
	for (int i = 0; i < stud.size; i++)
	{
		student s = stud.list[i];
		printf("%d) %s %s %s %s %.10s %.5s\n", i + 1, s.lastName, s.firstName, s.middleName, s.address, s.group, s.rate);
	}
	return stud;
}

void editStruct(student* stud)
{
	student newStud = fillStudent();
	strcpy(stud->firstName, newStud.firstName);
	strcpy(stud->group, newStud.group);
	strcpy(stud->lastName, newStud.lastName);
	strcpy(stud->middleName, newStud.middleName);
	strcpy(stud->rate, newStud.rate);
	strcpy(stud->address, newStud.address);
}

student* deleteStruct(students stud)
{
	int newSize = stud.size - 1;
	student* list = (student *)malloc(newSize * sizeof(student));
	for (int i = 0, k = 0; i < newSize; i++, k++)
	{
		if (i + 1 != stud.selected || k != i)
			list[i] = stud.list[k];
		else
			i--;
	}
	return list;
}

students seleсtStudent()
{
start:
	students result = showStudents();
	printf("Select student to edit: ");
	result.selected = test(_getch());
	clearScreen();
	if (result.selected < 1 || result.selected > result.size)
	{
		printf("Selected student does not exist\n");
		goto start;
	}
	return result;
}

int editStudent()
{
	students stud = seleсtStudent();
	editStruct(&stud.list[stud.selected - 1]);
	if (FILE* file = openFile("wb"))
	{
		fwrite(stud.list, stud.size, sizeof(student), file);
		fclose(file);
	}
	return 0;
}

int deleteStudent()
{
	students stud = seleсtStudent();
	student* newList = deleteStruct(stud);
	if (FILE* file = openFile("wb"))
	{
		fwrite(newList, stud.size - 1, sizeof(student), file);
		fclose(file);
	}
	return 0;
}

int searchStudent()
{
	char searchString[125];
	printf("Enter search string: ");
	scanf("%s", searchString);
	students stud = readFile();
	for (int i = 0; i < stud.size; i++)
	{
		student s = stud.list[i];
		if (strstr(s.firstName, searchString) != NULL ||
			strstr(s.lastName, searchString) != NULL ||
			strstr(s.middleName, searchString) != NULL ||
			strstr(s.address, searchString) != NULL ||
			strstr(s.group, searchString) != NULL ||
			strstr(s.rate, searchString) != NULL)
		{
			printf("%d) %s %s %s %s %.10s %.5s\n", i + 1, s.lastName, s.firstName, s.middleName, s.address, s.group, s.rate);
		}
	}
	return 0;
}

int sortStudents()
{
	printf("1) First name\n");
	printf("2) Last name\n");
	printf("3) Middle name\n");
	printf("4) Address\n");
	printf("5) Group\n");
	printf("6) Rate\n");
	printf("Enter sorting field: ");
	int n = test(_getch());
	students stud = readFile();
	sortStructs(stud.list, stud.size, n);
	if (FILE* file = openFile("wb"))
	{
		fwrite(stud.list, stud.size, sizeof(student), file);
		fclose(file);
	}
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

void checkOrCreateFile()
{
	if (!file_exist(datname))
		fclose(openFile("wb"));
}

int main()
{
	checkOrCreateFile();
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
		system("pause");
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