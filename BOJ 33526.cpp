#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<string> base = { "ZNA", "NAZ", "AZN" };
    int size = 3 * N;

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            int blockRow = i / N;
            int blockCol = j / N;

            cout << base[blockRow][blockCol];
        }

        cout << "\n";
    }

    return 0;
}