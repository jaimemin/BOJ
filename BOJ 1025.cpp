#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int func(int N, int M, const vector<string>& grid) 
{
    int largestPerfectSquare = -1;

    for (int startRow = 0; startRow < N; startRow++) 
    {
        for (int startCol = 0; startCol < M; startCol++) 
        {
            for (int rowDiff = -N; rowDiff < N; rowDiff++) 
            {
                for (int colDiff = -M; colDiff < M; colDiff++) 
                {
                    if (rowDiff == 0 && colDiff == 0)
                    {
                        continue;
                    }

                    int row = startRow;
                    int col = startCol;
                    string number;

                    while (row >= 0 && row < N 
                        && col >= 0 && col < M) 
                    {
                        number += grid[row][col];

                        int num = stoi(number);

                        int root = sqrt(num);

                        if (root * root == num) 
                        {
                            largestPerfectSquare = max(largestPerfectSquare, num);
                        }

                        row += rowDiff;
                        col += colDiff;
                    }
                }
            }
        }
    }

    return largestPerfectSquare;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> grid[i];
    }

    cout << func(N, M, grid) << "\n";

    return 0;
}
