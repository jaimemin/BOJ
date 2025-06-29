#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int OFFSET = 10000;

const int MAXSUM = 20000;

int findMinCoins(int N, int M, vector<int>& coins)
{
    vector<int> dist(MAXSUM + 1, -1);
    dist[OFFSET] = 0;

    queue<int> q;
    q.push(OFFSET);

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

        if (idx == M + OFFSET)
        {
            return dist[idx];
        }

        for (int c : coins)
        {
            int nextIdx = idx + c;

            if (nextIdx < 0 || nextIdx > MAXSUM)
            {
                continue;
            }

            if (dist[nextIdx] == -1)
            {
                dist[nextIdx] = dist[idx] + 1;

                q.push(nextIdx);
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    if (N == 0)
    {
        cout << (M == 0 ? 0 : -1) << "\n";

        return 0;
    }

    vector<int> coins(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    int answer = findMinCoins(N, M, coins);
    cout << answer << "\n";

    return 0;
}