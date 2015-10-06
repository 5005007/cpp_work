#include <iostream>
#include <ctime>
#include <conio.h>
#include <string>
#include <vector>
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

void printVector(vector<int> vec) {
	cout << vec[0] << "={";
	for (int i = 1; i < vec.size(); i++) {
		if (i > 1) {
			cout << ",";
		}
		cout << vec[i];
	}
	cout << "}\n";
}

vector<int> findDivisor(int n, vector<int> vec) {
	vec.insert(vec.end(), n);
	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			vec.insert(vec.end(), i);
		}
	}
	return vec;
}

void check(vector<vector<int>> targetVector) {
	for (int i = 0; i < targetVector.size(); i++) {
		long sum = 0;
		for (int j = 1; j < targetVector[i].size(); j++) {
			sum += targetVector[i][j];
		}
		if (targetVector[i][0] == sum) {
			printVector(targetVector[i]);
		}
	}
}

int main() {
	vector<vector<int>> targetVector;
	int n1 = getNumber();
	int n2 = getNumber();
	for (int n = n1; n < n2; n++) {
		vector<int> vec;
		targetVector.insert(targetVector.end(), findDivisor(n, vec));
	}
	check(targetVector);
	system("pause");
	return 0;
}
