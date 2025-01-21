#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int t = 0; t < 3; ++t) 
    { // 세 개의 입력 처리
        int N;
        cin >> N;

        vector<pair<int, int>> coins(N);
        int totalSum = 0;

        for (int i = 0; i < N; i++) 
        {
            cin >> coins[i].first >> coins[i].second; // 동전 금액과 개수 입력

            totalSum += coins[i].first * coins[i].second;
        }

        // 총합이 홀수면 반으로 나눌 수 없음
        if (totalSum % 2 != 0)
        {
            cout << 0 << "\n";

            continue;
        }

        int target = totalSum / 2;

        // DP 배열: dp[i]는 금액 i를 만들 수 있는지 여부
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // 금액 0은 항상 만들 수 있음

        for (auto coin : coins) 
        {
            int value = coin.first;
            int count = coin.second;

            // 동전의 개수 제한을 고려한 DP 업데이트
            for (int j = target; j >= 0; j--) 
            {
                if (dp[j])
                {
                    for (int k = 1; k <= count && j + k * value <= target; k++) 
                    {
                        dp[j + k * value] = 1;
                    }
                }
            }
        }

        // 목표 금액(target)을 만들 수 있으면 1, 없으면 0 출력
        cout << dp[target] << "\n";
    }

    return 0;
}