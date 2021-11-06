#include <iostream>
using namespace std;

void init(bool bubbles[][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            bubbles[i][j] = true;
        }
    }
}

void pop(bool bubbles[][12], int start[], int end[]) {
    for (int i = start[0] - 1; i < end[0]; ++i) {
        for (int j = start[1] - 1; j < end[1]; ++j) {
            if (bubbles[i][j]) {
                cout << " >POP!< " << endl;
                bubbles[i][j] = false;
            }
        }
    }
}

int film(bool bubbles[][12], int start[], int end[]) {
    int count = 0;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (bubbles[i][j]) cout << "O";
            else {
                cout << "X";
                count++;
            }
        }
        cout << endl;
    }
    return count;
}

int main()
{
    bool bubbles[12][12];
    init(bubbles);
    int count = 0;
    int start[2];
    int end[2];
    int temp;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (bubbles[i][j]) cout << "O";
            else cout << "X";
        }
        cout << endl;
    }
    while (count < 144) {
        cout << "Enter a start point coordinate (X,Y): ";
        for (int i = 0; i < 2;) {
            cin >> temp;
            if (temp < 1 || temp > 12) cout << "Incorrect! Coordinate must be in range from 1 to 12! Try again. ";
            else {
                start[i] = temp;
                i++;
            }
        }
        cout << "Enter an end point coordinate (X,Y): ";
        for (int i = 0; i < 2;) {
            cin >> temp;
            if (temp < 1 || temp > 12) cout << "Incorrect! Coordinate must be in range from 1 to 12! Try again. ";
            else {
                if (temp < start[i]) {
                    end[i] = start[i];
                    start[i] = temp;
                }   else end[i] = temp;
                i++;
            }
        }
        
        pop(bubbles, start, end);
        count = film(bubbles, start, end);
    }
    cout << "Bubbles run out.";
}
