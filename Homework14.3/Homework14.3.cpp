#include <iostream>
using namespace std;

int main()
{
    int snake[5][5];
    int count = 0;
    int j=0;
    int shift = 1;
    for (int i = 0; i < 5; ++i) {
        snake[i][j] = count;
        j += shift;
        count++;
        for (; count % 5 != 0;) {
            snake[i][j] = count;
            count++;
            j += shift;
        }
        shift *= -1;
        j += shift;
    }
    for (int i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            cout << snake[i][j] << " ";
        }
        cout << endl;
    }

}
