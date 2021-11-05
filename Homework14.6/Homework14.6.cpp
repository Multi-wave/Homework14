#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <float> V;
    float M[4][4];
    vector <float> R;
    float temp;

    cout << "Enter a numbers of V: ";
    for (int i = 0; i < 4; ++i) {
        cin >> temp;
        V.push_back(temp);
    }
    cout << "Enter a numbers of M: ";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> M[i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        temp = 0;
        for (int j = 0; j < 4; ++j) {
            temp += V[j] * M[j][i];
        }
        R.push_back(temp); 
    }
    for (int i = 0; i < 4; ++i) {
        cout << R[i] << " ";
    }
}
