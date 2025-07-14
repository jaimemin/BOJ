#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[105][11][11];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, J, S, H, K;
    cin >> N >> J >> S >> H >> K;

    vector<string> stage(3);

    for (int i = 0; i < 3; i++)
    {
        cin >> stage[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[1][0][0] = H;

    vector<char> obs(N + 1, ' ');

    for (int col = 2; col <= N - 1; col++)
    {
        if (stage[1][col - 1] == '^')
        {
            obs[col] = '^';
        }
        else if (stage[1][col - 1] == 'v')
        {
            obs[col] = 'v';
        }
        else if (stage[0][col - 1] == '.')
        {
            obs[col] = '.';
        }
    }

    for (int col = 1; col < N; col++)
    {
        for (int jump = 0; jump <= J; jump++)
        {
            for (int slide = 0; slide <= S; slide++)
            {
                if (dp[col][jump][slide] == -1)
                {
                    continue;
                }

                int hp = dp[col][jump][slide];
                int ncol = col + 1;
                char o = obs[ncol];

                if (o == ' ')
                {
                    if (dp[ncol][jump][slide] < hp)
                    {
                        dp[ncol][jump][slide] = hp;
                    }
                }
                else if (o == '^')
                {
                    if (jump + 1 <= J)
                    {
                        dp[ncol][jump + 1][slide] = max(dp[ncol][jump + 1][slide], hp);
                    }

                    if (hp - K > 0)
                    {
                        dp[ncol][jump][slide] = max(dp[ncol][jump][slide], hp - K);
                    }
                }
                else if (o == 'v')
                {
                    if (jump + 2 <= J)
                    {
                        dp[ncol][jump + 2][slide] = max(dp[ncol][jump + 2][slide], hp);
                    }

                    if (hp - K > 0)
                    {
                        dp[ncol][jump][slide] = max(dp[ncol][jump][slide], hp - K);
                    }
                }
                else if (o == '.')
                {
                    if (slide + 1 <= S)
                    {
                        dp[ncol][jump][slide + 1] = max(dp[ncol][jump][slide + 1], hp);
                    }

                    if (hp - K > 0)
                    {
                        dp[ncol][jump][slide] = max(dp[ncol][jump][slide], hp - K);
                    }
                }
            }
        }
    }

    int answer = -1;

    for (int jump = 0; jump <= J; jump++)
    {
        for (int slide = 0; slide <= S; slide++)
        {
            answer = max(answer, dp[N][jump][slide]);
        }
    }

    cout << answer << "\n";

    return 0;
}