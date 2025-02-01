#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const long long NEG_INF = LLONG_MIN;

const int MAX = 500 + 50;

long long dp[MAX][MAX];

long long bestNextArr[MAX][MAX];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<long long> x(M), c(M);

    for (int i = 0; i < M; i++)
    {
        cin >> x[i] >> c[i];
    }

    vector<pair<long long, long long>> tmp(M);

    for (int i = 0; i < M; i++)
    {
        tmp[i] = { x[i], c[i] };
    }

    sort(tmp.begin(), tmp.end(), [](auto& a, auto& b) {
        return a.first < b.first;
    });

    for (int i = 0; i < M; i++)
    {
        x[i] = tmp[i].first;
        c[i] = tmp[i].second;

        if (c[i] > N)
        {
            c[i] = N;
        }
    }

    vector<vector<int>> nxt(M);

    for (int i = 0; i < M; i++) 
    {
        for (int j = i + 1; j < M; j++) 
        {
            if (x[j] % x[i] == 0) 
            {
                nxt[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int l = 0; l <= N; l++) 
        {
            dp[i][l] = NEG_INF;

            bestNextArr[i][l] = NEG_INF;
        }

        dp[i][0] = 0;
    }

    for (int i = M - 1; i >= 0; i--)
    {
        for (int l = 0; l <= N; l++) 
        {
            long long bestVal = NEG_INF;

            for (int j : nxt[i]) 
            {
                bestVal = max(bestVal, dp[j][l]);
            }

            bestNextArr[i][l] = bestVal;
        }

        for (int l = 1; l <= N; l++) 
        {
            int limitP = min((long long)l, c[i]);
            long long bestVal = NEG_INF;

            for (int p = 1; p <= limitP; p++)
            {
                long long sumNow = p * x[i];
                int rem = l - p;

                if (rem == 0)
                {
                    bestVal = max(bestVal, sumNow);

                    continue;
                }
              
                long long tail = bestNextArr[i][rem];

                if (tail != NEG_INF) 
                {
                    bestVal = max(bestVal, sumNow + tail);
                }
            }

            dp[i][l] = bestVal;
        }
    }

    long long answer = NEG_INF;

    for (int i = 0; i < M; i++)
    {
        answer = max(answer, dp[i][N]);
    }

    cout << (answer == NEG_INF ? -1 : answer) << "\n";

    return 0;
}
