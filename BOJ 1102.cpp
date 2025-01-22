#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N, P;

int cost[16][16];

int dp[1 << 16]; // dp[bitmask]: 현재 상태에서 최소 비용

string state;

int getBits(int bitmask)
{
    int cnt = 0;

    while (bitmask)
    {
        cnt += (bitmask % 2);

        bitmask /= 2;
    }

    return cnt;
}

// 최소 비용 계산 함수
int solve(int bitmask) 
{
    int active = getBits(bitmask); // 켜져 있는 발전소의 개수

    if (active >= P)
    {
        return 0; // 필요한 만큼 켜져 있으면 추가 비용 없음
    }

    if (dp[bitmask] != -1)
    {
        return dp[bitmask];
    }

    int result = INF;

    for (int i = 0; i < N; i++) 
    {
        if (bitmask & (1 << i)) 
        { // i번째 발전소가 켜져 있는 경우
            for (int j = 0; j < N; j++) 
            {
                if (!(bitmask & (1 << j)))
                { // j번째 발전소가 꺼져 있는 경우
                    result = min(result, cost[i][j] + solve(bitmask | (1 << j)));
                }
            }
        }
    }

    return dp[bitmask] = result;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> cost[i][j];
        }
    }

    cin >> state;
    cin >> P;

    int initialBitmask = 0;

    for (int i = 0; i < N; i++) 
    {
        if (state[i] == 'Y') 
        {
            initialBitmask |= (1 << i);
        }
    }

    memset(dp, -1, sizeof(dp));

    int result = solve(initialBitmask);

    cout << (result == INF ? -1 : result) << "\n";

    return 0;
}
