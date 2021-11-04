#include <iostream>
using namespace std;

int main()
{
    int A[4][4];
    int B[4][4];
    std::cout << "Enter numbers of matrix A:";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> A[i][j];
        }
    }
    std::cout << "Enter numbers of matrix B:";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (A[i][j] != B[i][j]) {
                cout << "Matrix A & B not equal!";
                return 0;
            }
        }
    }
    cout << "Matrix A & B equal.";
}