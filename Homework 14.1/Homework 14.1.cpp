#include <iostream>
#include <vector>

int main()
{
    int tableware[2][6] = { {4,3,3,3,3,3},{4,3,3,3,3,3} };
    int dishes[2][6] = { {3,2,2,2,2,2},{3,2,2,2,2,2} };
    int chairs[2][6] = { {1,1,1,1,1,1},{1,1,1,1,1,1} };

    chairs[0][4]++;
    tableware[1][2]--;
    tableware[1][0]--;
    tableware[1][2]++;
    dishes[1][0]--;

}

