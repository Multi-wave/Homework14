#include <iostream>
using namespace std;

int main()
{
	int field[5][5][10];
	int temp;
	int layer;
	bool correct = false;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ) {
			cout << "Enter a high of field (" << (i + 1) << "," << (j + 1) << "): ";
			cin >> temp;
			if (temp < 0 || temp > 9) cout << "Incorrect! High must be in range from 0 to 9! Try again! \n";
			else {
				for (int k = 0; k < 10; ++k) {
					if (k <= temp && temp != 0) field[i][j][k] = 1;
					else field[i][j][k] = 0;
				}
				++j;
			}
		}
	}
	cout << "Now enter a layer number: ";
	while (!correct) {
		cin >> layer;
		if (layer < 0 || layer > 9) cout << "Incorrect! Layer must be in range from 0 to 9! Try again! \n";
		else {
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					cout << field[i][j][layer];
				}
				cout << endl;
			}
			correct = true;
		}
	}
}
