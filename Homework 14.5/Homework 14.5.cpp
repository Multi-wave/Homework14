#include <iostream>
using namespace std;

int main()
{
    float M[4][4];
    std::cout << "Enter numbers of matrix M:";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) M[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
