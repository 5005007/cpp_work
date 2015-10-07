#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

bool test(char ch, const char *keys, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		if (keys[i] == ch) {
			return true;
		}
	}
	return false;
}

int getNumber()
{
	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	string n;
	char ch;

	while ((ch = _getch()) != '\r')
		if (test(ch, numbers, 10) || ch == '\b') {
			n += ch;
			cout << ch;
		}

	cout << endl;
	return atoi(n.c_str());
}

int main() {
	cout << "n1=";
	int n1 = getNumber();
	cout << "n2=";
	int n2 = getNumber();
	int sum;
	for (int i = n1; i < n2; i++) {
		sum = 0;
		for (int n = 1; n <= i / 2; n++) {
			if (i % n == 0) {
				sum = sum + n;
			}
		}
		if (i == sum) {
			printf("%d is perfect!\n", i);
		}
	}
	system("pause");
	return 0;
}

