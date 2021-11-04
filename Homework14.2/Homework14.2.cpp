#include <iostream>
using namespace std;

int main()
{
    char table[3][3]{ {' ',' ',' '},{' ',' ',' '} , {' ',' ',' '} };
    int player = 1;
    int count = 1;
    int x;
    int y;
    bool win = false;
    for (count; count <= 9; ++count) {
        player = (count % 2 == 0 ? 2 : 1);
        cout << "Player " << player << " your turn: ";
        cin >> x >> y;
        if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
            if (table[x - 1][y - 1] == ' ') {
                table[x - 1][y - 1] = (player == 1 ? 'X' : 'O');
                if ((table[x - 1][0] == table[x - 1][1] && table[x - 1][0] == table[x - 1][2]) || (table[0][y - 1] == table[1][y - 1] && table[0][y - 1] == table[2][y - 1])) {
                    win = true;
                    break;
                }
                cout << "Table:" << endl;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        cout << table[i][j];
                    }
                    cout << endl;
                }
            }
            else {
                count--;
                cout << "This sell is occupied! Try again!" << endl;
            }
        }
        else {
            count--;
            cout << "The entered coordinate is not supported! Try again!" << endl;
        }
        
        cout << endl;
    }
    if (win) cout << "Player " << player << " won!";
    else cout << "Draw!";
}
