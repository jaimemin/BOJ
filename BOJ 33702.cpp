#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int y, x;
} Dir;

Dir moveDir[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

vector<vector<int>> adj(9);

int whites[4] = { 1, 3, 5, 7 };

void dfs(int u, int mask, long long& result)
{
    if (mask == (1 << 9) - 1)
    {
        result++;

        return;
    }

    for (int v : adj[u]) 
    {
        if (!(mask & (1 << v))) 
        {
            dfs(v, mask | (1 << v), result);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K;
    cin >> K;

    for (int i = 0; i < 9; i++) 
    {
        int y = i / 3;
        int x = i % 3;

        for (int k = 0; k < 4; k++) 
        {
            int nextY = y + moveDir[k].y;
            int nextX = x + moveDir[k].x;

            if (nextY >= 0 && nextY < 3 && nextX >= 0 && nextX < 3)
            {
                int j = nextY * 3 + nextX;

                adj[i].push_back(j);
            }
        }
    }

    int start = K - 1;
    long long answer = 0;

    for (int w : whites) 
    {
        if (start == w)
        {
            cout << 0 << "\n";

            return 0;
        }
    }

    dfs(start, 1 << start, answer);

    cout << answer << "\n";

    return 0;
}