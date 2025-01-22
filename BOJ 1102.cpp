#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N, P;

int cost[16][16];

int dp[1 << 16]; // dp[bitmask]: ���� ���¿��� �ּ� ���

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

// �ּ� ��� ��� �Լ�
int solve(int bitmask) 
{
    int active = getBits(bitmask); // ���� �ִ� �������� ����

    if (active >= P)
    {
        return 0; // �ʿ��� ��ŭ ���� ������ �߰� ��� ����
    }

    if (dp[bitmask] != -1)
    {
        return dp[bitmask];
    }

    int result = INF;

    for (int i = 0; i < N; i++) 
    {
        if (bitmask & (1 << i)) 
        { // i��° �����Ұ� ���� �ִ� ���
            for (int j = 0; j < N; j++) 
            {
                if (!(bitmask & (1 << j)))
                { // j��° �����Ұ� ���� �ִ� ���
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
