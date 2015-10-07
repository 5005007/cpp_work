#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

bool test(char ch, const char *keys, unsigned int size) {
	for (int i = 0; i < size; i++) {
		if (keys[i] == ch) {
			return true;
		}
	}
	return false;
}

int getNumber() {
	char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };
	string n;
	char ch;

	while ((ch = getch()) != '\r') {
		if (test(ch, numbers, 10)) {
			n += ch;
			cout << ch;
		}
	}

	cout << endl;
	return atoi(n.c_str());
}

void printVector(vector<int> vec) {
	cout << "array = {";
	for (int i = 0; i < vec.size(); i++) {
		if (i > 0) {
			cout << ",";
		}
		cout << vec[i];
	}
	cout << "}\n";
}

int main() {
	vector<int> targetVector;
	cout << "n=";
	int n = getNumber();

	srand(time(0));
	for (int i = 0; i < n; i++) {
		targetVector.insert(targetVector.end(), rand() % 100 + 1);
	}
	printVector(targetVector);
	bool needComma = false;
	cout << "result = {";
	for (int i = 1; i < n - 1; i++) {
		if ((targetVector[i - 1] < targetVector[i]) && (targetVector[i] < targetVector[i + 1])) {
			if (needComma) {
				cout << ", ";
			}
			needComma = true;
			cout << i + 1;
		}
	}
	cout << "}\n";
	system("pause");
	return 0;
}
