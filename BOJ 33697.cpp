#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> graphUp(N + 1), graphDown(N + 1);

    for (int i = 0; i < M; i++) 
    {
        int x, y;
        cin >> x >> y;

        graphUp[x].push_back(y);
        graphDown[y].push_back(x);
    }

    vector<int> dpUp(N + 1, 0), dpDown(N + 1, 0);
    vector<int> colorUp(N + 1, 0), colorDown(N + 1, 0);

    for (int i = 1; i <= Q; i++)
    {
        int x, d, c;
        cin >> x >> d >> c;

        if (d == 1) 
        {
            if (i > dpUp[x]) 
            {
                dpUp[x] = i;
                colorUp[x] = c;
            }
        }
        else 
        {
            if (i > dpDown[x]) 
            {
                dpDown[x] = i;
                colorDown[x] = c;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int nxt : graphUp[i]) 
        {
            if (dpUp[i] > dpUp[nxt])
            {
                dpUp[nxt] = dpUp[i];
                colorUp[nxt] = colorUp[i];
            }
        }
    }

    for (int i = N; i >= 1; i--)
    {
        for (int nxt : graphDown[i]) 
        {
            if (dpDown[i] > dpDown[nxt]) 
            {
                dpDown[nxt] = dpDown[i];
                colorDown[nxt] = colorDown[i];
            }
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        int finalTime = max(dpUp[i], dpDown[i]);
        int finalColor = 0;

        if (finalTime == 0)
        {
            finalColor = 0;
        }
        else
        {
            if (dpUp[i] >= dpDown[i])
            {
                finalColor = colorUp[i];
            }
            else
            {
                finalColor = colorDown[i];
            }
        }

        cout << finalColor << (i == N ? "\n" : " ");
    }

    cout << "\n";

    return 0;
}