#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N;

        vector<int> coins(N);

        for (int i = 0; i < N; ++i) 
        {
            cin >> coins[i];
        }

        cin >> M;

        // DP 배열: dp[i]는 금액 i를 만드는 방법의 수
        vector<int> dp(M + 1, 0);
        dp[0] = 1; // 금액 0을 만드는 방법은 1가지 (아무것도 사용하지 않음)

        // 동전으로 DP 배열 업데이트
        for (int coin : coins) 
        {
            for (int j = coin; j <= M; j++)
            {
                dp[j] += dp[j - coin];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}