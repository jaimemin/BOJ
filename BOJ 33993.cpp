#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, R, C, W;
    cin >> N >> R >> C >> W;

    int k = (W - 1) / 2;

    vector<vector<char>> grid(R + 1, vector<char>(C + 1, 0));

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        grid[x][y] = 1;
    }

    vector<vector<int>> S(R + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++) 
        {
            S[i][j] = grid[i][j] + S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
        }
    }

    int bestCount = -1;
    int bestX = 0, bestY = 0;

    for (int x = 1; x <= R; x++) 
    {
        for (int y = 1; y <= C; y++) 
        {
            if (grid[x][y] == 0)
            {
                int x1 = max(1, x - k);
                int x2 = min(R, x + k);
                int y1 = max(1, y - k);
                int y2 = min(C, y + k);

                int cnt = S[x2][y2] - S[x1 - 1][y2] - S[x2][y1 - 1] + S[x1 - 1][y1 - 1];

                if (cnt > bestCount
                    || (cnt == bestCount
                        && (x < bestX || (x == bestX && y < bestY))))
                {
                    bestCount = cnt;
                    bestX = x;
                    bestY = y;
                }
            }
        }
    }

    cout << bestCount << "\n";
    cout << bestX << " " << bestY << "\n";

    return 0;
}