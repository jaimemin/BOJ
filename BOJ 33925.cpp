#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int dp[105][11][11]; 

enum Obs { NONE, LOW, HIGH, UPPER };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, J, S, H, K;
    cin >> N >> J >> S >> H >> K;

    vector<string> a(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }

    vector<Obs> obs(N + 1, NONE);

    for (int c = 2; c <= N - 1; c++)
    {
        if (a[0][c - 1] == 'v' || a[1][c - 1] == 'v') 
        {
            obs[c] = UPPER;
        }
        else if (a[1][c - 1] == '^')
        {
            obs[c] = HIGH;
        }
        else if (a[2][c - 1] == '^') 
        {
            obs[c] = LOW;
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[1][0][0] = H;

    for (int c = 1; c < N; c++) 
    {
        for (int j = 0; j <= J; j++)
        {
            for (int s = 0; s <= S; ++s)
            {
                if (dp[c][j][s] != -1)
                {
                    int hp = dp[c][j][s];
                    int nc = c + 1;
                    switch (obs[nc])
                    {
                    case NONE: 
                        dp[nc][j][s] = max(dp[nc][j][s], hp);

                        break;
                    case LOW:
                        if (j + 1 <= J)
                        {
                            dp[nc][j + 1][s] = max(dp[nc][j + 1][s], hp);
                        }

                        if (hp - K > 0)
                        {
                            dp[nc][j][s] = max(dp[nc][j][s], hp - K);
                        }

                        break;
                    case HIGH:
                        if (j + 2 <= J)
                        {
                            dp[nc][j + 2][s] = max(dp[nc][j + 2][s], hp);
                        }

                        if (hp - K > 0)
                        {
                            dp[nc][j][s] = max(dp[nc][j][s], hp - K);
                        }

                        break;
                    case UPPER:
                        if (s + 1 <= S)
                        {
                            dp[nc][j][s + 1] = max(dp[nc][j][s + 1], hp);
                        }

                        if (hp - K > 0)
                        {
                            dp[nc][j][s] = max(dp[nc][j][s], hp - K);
                        }

                        break;
                    }
                }
            }
        }
    }

    int answer = -1;

    for (int j = 0; j <= J; j++)
    {
        for (int s = 0; s <= S; s++)
        {
            answer = max(answer, dp[N][j][s]);
        }
    }

    cout << answer << "\n";

    return 0;
}
