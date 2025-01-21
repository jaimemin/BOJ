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

        // DP �迭: dp[i]�� �ݾ� i�� ����� ����� ��
        vector<int> dp(M + 1, 0);
        dp[0] = 1; // �ݾ� 0�� ����� ����� 1���� (�ƹ��͵� ������� ����)

        // �������� DP �迭 ������Ʈ
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