/*
Ayush Sharma
30 March 2017
*/

#include <iostream>
#include <Windows.h>

using namespace std;

void init();
void render();
void update(bool a);
void check();
void life();
bool arr[20][20];
int n[20][20];

int main() {

	int x;
	init();
	while (true) {
		render();
		cout << "Operations:\n1. Birth Cell\n2. Kill Cell\n3. Run One Life Iteration\n4. Run 50 Life Iterations\n5. Clear\nEnter: ";
		cin >> x;
		switch (x) {
		case 1:
			update(true);
			break;
		case 2:
			update(false);
			break;
		case 3:
			life();
			break;
		case 4:
			for (int i = 0; i < 50; i++) {
				life();
				render();
				Sleep(200);
			}
			break;
		case 5:
			init();
			break;
		}
	}

	system("pause");
	return 0;
}

void init() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			arr[i][j] = false;
		}
	}
}

void render() {
	system("cls");
	cout << "__|ABCDEFGHIJKLMNOPQRST|ABCDEFGHIJKLMNOPQRST|ABCDEFGHIJKLMNOPQRST|__\n";
	for (int i = 0; i < 20; i++) {
		if (i + 1 < 10) {
			cout << " ";
		}
		cout << i + 1 << "|";
		for (int j = 0; j < 20; j++) {
			if (arr[i][j] == false) {
				cout << n[i][j];
			}
			else {
				cout << n[i][j];
			}
		}
		cout << "|";
		for (int j = 0; j < 20; j++) {
			if (arr[i][j] == false) {
				cout << ".";
			}
			else {
				cout << "O";
			}
		}
		cout << "|";
		for (int j = 0; j < 20; j++) {
			if (arr[i][j] == false) {
				cout << "0";
			}
			else {
				cout << "1";
			}
		}
		cout << "|" << i + 1 << "\n";
	}
	cout << "  |      NEIGHBORS     |        CELLS       |       BOOL[]       |\n";
}

void update(bool a) {
	int y, z;
	char x;
	cout << "Enter letter coordinate: ";
	cin >> x;
	z = (int)x;
	if (z >= 97) {
		z -= 97;
	}
	else {
		z -= 65;
	}
	cout << "Enter number coordinate: ";
	cin >> y;
	arr[y - 1][z] = a;

	check();
}

void check() {
	int x = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 && j == 0) {
				if (arr[i][j + 1]) {
					x++;
				}
				if (arr[i + 1][j + 1]) {
					x++;
				}
				if (arr[i][j + 1]) {
					x++;
				}
				n[i][j] = x;
				x = 0;
			}
			else if (i == 19 && j == 0) {
				if (arr[i - 1][j]) {
					x++;
				}
				if (arr[i - 1][j + 1]) {
					x++;
				}
				if (arr[i][j + 1]) {
					x++;
				}
				n[i][j] = x;
				x = 0;
			}
			else if (i == 0 && j == 19) {
				if (arr[i][j - 1]) {
					x++;
				}
				if (arr[i + 1][j - 1]) {
					x++;
				}
				if (arr[i - 1][j]) {
					x++;
				}
				n[i][j] = x;
				x = 0;
			}
			else if (i == 19 && j == 19) {
				if (arr[i][j - 1]) {
					x++;
				}
				if (arr[i - 1][j - 1]) {
					x++;
				}
				if (arr[i - 1][j]) {
					x++;
				}
				n[i][j] = x;
				x = 0;
			}
			else {
				if (arr[i - 1][j]) {
					x++;
				}
				if (arr[i - 1][j - 1]) {
					x++;
				}
				if (arr[i - 1][j + 1]) {
					x++;
				}
				if (arr[i + 1][j]) {
					x++;
				}
				if (arr[i + 1][j + 1]) {
					x++;
				}
				if (arr[i + 1][j - 1]) {
					x++;
				}
				if (arr[i][j - 1]) {
					x++;
				}
				if (arr[i][j + 1]) {
					x++;
				}
				n[i][j] = x;
				x = 0;
			}
		}
	}
}

void life() {
	check();
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (arr[i][j]) {
				if (n[i][j] != 2 && n[i][j] != 3) {
					arr[i][j] = false;
				}
			}
			if (!arr[i][j]) {
				if (n[i][j] == 3) {
					arr[i][j] = true;
				}
			}
		}
	}
}

