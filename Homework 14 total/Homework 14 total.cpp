#include <iostream>
using namespace std;

void initialise(bool field[][10], char result[][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            field[i][j] = false;
            result[i][j] = '~';
        }
    }
}

void arrangement(bool field[][10], int cell) {
    int count = 1;
    int startX;
    int startY;
    int endX;
    int endY;
    cout << endl;
    if (cell == 1) {
        while (count < 5) {
            cout << "Enter a coordinate 1-cell ship " << count << ":";
            cin >> startX >> startY;
            if (startX < 0 || startX > 9 || startY < 0 || startY > 9) {
                cout << "Incorrect. Coordinate must be in range from 0 to 9. Try again." << endl;
            }
            else if (field[startY][startX]) {
                cout << "Incorrect. Cell is already occupied. Try again." << endl;
            }
            else {
                field[startY][startX] = true;
                count++;
            }
        }
    }
    else {
        while (count < (6 - cell)) {
            bool correct = true;
            cout << "Enter a coordinate of " << cell << "-cell ship " << count << ":";
            cin >> startX >> startY >> endX >> endY;
            if (startX < 0 || startX > 9 || endX < 0 || endX > 9 || startY < 0 || startY > 9 || endY < 0 || endY > 9) {
                cout << "Incorrect. Coordinate must be in range from 0 to 9. Try again." << endl;
            }
            else {
                int temp;
                if (startX > endX) {
                    temp = startX;
                    startX = endX;
                    endX = temp;
                }
                if (startY > endY) {
                    temp = startY;
                    startY = endY;
                    endY = temp;
                }
                if (endX != startX && endY != startY) {
                    cout << "Incorrect. The ship cannot be positioned diagonally. Try again." << endl;
                }
                else {
                    if ((endX - startX) != (cell - 1) && (endY - startY) != (cell - 1)) {
                        cout << "Incorrect. Length of ship must be " << cell << ". Try again." << endl;
                    }
                    else {
                        if (endX != startX) {
                            for (int i = startX; i <= endX; ++i) {
                                if (!field[startY][i]) {
                                    field[startY][i] = true;
                                }
                                else {
                                    cout << "Incorrect. Cell is already occupied. Try again." << endl;
                                    correct = false;
                                    break;
                                }
                            }
                            if (correct) count++;
                        }
                        else {
                            for (int i = startY; i <= endY; ++i) {
                                if (!field[i][startX]) {
                                    field[i][startX] = true;
                                }
                                else {
                                    cout << "Incorrect. Cell is already occupied. Try again." << endl;
                                    correct = false;
                                    break;
                                }
                            }
                            if (correct) count++;
                        }
                    }
                }
            }
        }

    }
}

void message(int player, char result_1[][10], char result_2[][10]) {
    if (player == 1) {
        cout << "Player 2 field:" << endl;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << result_2[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << "Player 1, your move: ";
    }
    else {
        cout << "Player 1 field:" << endl;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << result_1[i][j];
            }
            cout << endl;
        }
        cout << endl;
        cout << "Player 2, your move: ";
    }
}

int main()
{
    bool field_1[10][10];
    bool field_2[10][10];
    char result_1[10][10];
    char result_2[10][10];
    initialise(field_1, result_1);
    initialise(field_2, result_2);
    int X;
    int Y;
    cout << "Player 1 arrange ships: ";
    for (int i = 1; i < 5; ++i) arrangement(field_1, i);
    cout << "Player 2 arrange ships: ";
    for (int i = 1; i < 5; ++i) arrangement(field_2, i);
    cout << "-----START-----" << endl;
    int player = 1;
    int win_1 = 0;
    int win_2 = 0;
    while (win_1 < 20 && win_2 < 20) {
        message(player, result_1, result_2);
        cin >> Y >> X;
        if (X < 0 || X > 9 || Y < 0 || Y > 9) {
            cout << "Incorrect. Coordinate must be in range from 0 to 9. Try again." << endl;
        }
        else {
            if (player == 1) {
                if (field_2[X][Y] && result_2[X][Y] == '~') {
                    cout << "HIT" << endl;
                    result_2[X][Y] = 'X';
                    win_1++;
                }
                else {
                    cout << "MISS" << endl;
                    if (result_2[X][Y] == '~') result_2[X][Y] = 'Y';
                    player *= -1;
                }
            }
            else {
                if (field_1[X][Y] && result_1[X][Y] == '~') {
                    cout << "HIT" << endl;
                    result_1[X][Y] = 'X';
                    win_2++;
                }
                else {
                    cout << "MISS" << endl;
                    if (result_1[X][Y] == '~') result_1[X][Y] = 'Y';
                    player *= -1;
                }
            }
        }
    }
    if (win_1 == 20) {
        cout << "Game over. Player 1 win.";
    }   else cout << "Game over. Player 2 win.";
}
