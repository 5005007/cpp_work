#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/*

����������� ������ � ���������� �������� �� �����.
��� ������ ����� ���������������� �������.
������ main �� ������ 30 �����, ���������������� ������� �� ������ 50 ����� ����.
������ �������� ������ ���� ������������

�������: �������, ���, ��������; �������� �����; ������; �������.
1)	���� ������� ��������;
2)	����� �� ����� ������� ��������;
3)	��������� �������� ���������;
4)	����� � ������� �������� �� ��������� ���������;
5)	���������� ������� �������� �� ��������� ���������;
6)	����� � ������� �������� �� ��������� ���������
7)	�������� ��������� �� ������� �� ��������� ���������;
8)	����� � ������� �������� �� ���������� ���������� ��������� ���������;
*/

struct student
{
	char* firstName;
	char* lastName;
	char* middleName;
	char* address;
	char* group;
	char* rate;
} s;

FILE *f;


int editStudent()
{
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

	printf("Enter first name");
	scanf("%s", &s.firstName);

	printf("Enter last name");
	scanf("%s", &s.lastName);

	printf("Enter middle name");
	scanf("%s", &s.middleName);

	printf("Enter address");
	scanf("%s", &s.address);

	printf("Enter group");
	scanf("%s", &s.group);

	printf("Enter rate");
	scanf("%s", &s.rate);

	fwrite(&s, sizeof(s), 1, f);

	return 1;
}

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
	clearScreen();
	printf("1) Add student\n");
	printf("2) Show students\n");
	printf("3) Edit student\n");
	printf("4) Search student\n");
	printf("5) Sort students\n");
	printf("6) Delete student\n");
	printf("Please enter choice:");
	return test(_getch());
}

int openFile()
{
	if (!(f = fopen("students", "a+b")))
	{
		printf("Error while file creating\n");
		return 0;
	}
}

int main()
{

	int rs = openFile();
start:
	switch (getNumber())
	{
	case 0:
		printf("Good bye!");
		break;
	case 1:
		addStudent();
		goto start;
		break;
	case 2:

		break;
	case 3:
		editStudent();
		goto start;
		break;
	case 4:
		searchStudent();
		goto start;
		break;
	case 5:
		sortStudents();
		goto start;
		break;
	case 6:
		deleteStudent();
		goto start;
		break;
	default:
		printf("Error! Please enter from 1 to 8.");
		goto start;
	}
	system("pause");

	return 0;
}