#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    // dp[i]: 돌이 i개 남았을 때 이기는 사람이 누구인지 저장 (1: 상근, 0: 창영)
    vector<int> dp(N + 1, 0);

    // 초기 조건 설정
    dp[1] = 1; // 상근이가 1개를 가져가서 승리

    if (N >= 2)
    {
        dp[2] = 0; // 창영이가 1개를 가져가서 승리
    }

    if (N >= 3)
    {
        dp[3] = 1; // 상근이가 3개를 가져가서 승리
    }

    // dp 배열 채우기
    for (int i = 4; i <= N; ++i) 
    {
        // 상근이가 돌을 1개 또는 3개 가져갈 수 있을 때,
        // 그 결과 창영이가 모두 이기는 경우라면 상근이가 패배.
        if (dp[i - 1] == 0 || dp[i - 3] == 0) 
        {
            dp[i] = 1; // 상근이가 승리
        }
        else {
            dp[i] = 0; // 창영이가 승리
        }
    }

    cout << (dp[N] ? "SK" : "CY") << "\n";

    return 0;
}