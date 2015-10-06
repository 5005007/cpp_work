#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
using namespace std;

const int C = 20;

bool test(char ch, const char *keys, unsigned int size)
{
	for (int i = 0; i<size; i++)
		if (keys[i] == ch) return true;
	return false;
}

int getNumber()
{
	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	string n;
	char ch;

	while ((ch = getch()) != '\r')//enter
		if (test(ch, numbers, 10))
		{
			n += ch;
			cout << ch;
		}

	cout << endl;
	return atoi(n.c_str());
}

void printArray(int* array) {
	cout << "array={";
	for (int i = 0; i < C; i++) {
		if (i > 0) {
			cout << ",";
		}
		cout << array[i];
	}
	cout << "}\n";
}

void quickSort(int* a, long N) {
	long i = 0, j = N;
	int temp, p;
	p = a[N >> 1];
	do {
		while (a[i] < p) i++;
		while (a[j] > p) j--;
		if (i <= j) {
			temp = a[i]; a[i] = a[j]; a[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(a, j);
	if (N > i) quickSort(a + i, N - i);
}

int check(int M, int* array) {
	if (C == 1) {
		return array[0] < M ? array[0] : 0;
	}
	double product = 1;
	double sum = 0;
	for (int i = 0; i < C; i++) {
		product = product * array[i];
		if (product >= M) {
			return sum;
		}
		else {
			sum = sum + array[i];
		}
	}
	return sum;
}

int main(){
	int targetArray[C];

	srand(time(0));
	for (int i = 0; i < C; i++) {
		targetArray[i] = rand() % 100 + 1;
	}
	printArray(targetArray);
	// Идея заключается в следующем:
	// чтобы использовать в сумме максимальное количество чисел,
	// необходимо перемножать минимальные элементы массива.
	// Поэтому сначала отсортируем массив.
	quickSort(targetArray, C-1);
	printArray(targetArray);
	cout << "M=";
	int M = getNumber();
	cout << "sum=" << check(M, targetArray) << "\n";
	system("pause");
	return 0;
}
