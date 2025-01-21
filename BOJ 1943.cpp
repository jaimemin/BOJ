#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int t = 0; t < 3; ++t) 
    { // �� ���� �Է� ó��
        int N;
        cin >> N;

        vector<pair<int, int>> coins(N);
        int totalSum = 0;

        for (int i = 0; i < N; i++) 
        {
            cin >> coins[i].first >> coins[i].second; // ���� �ݾװ� ���� �Է�

            totalSum += coins[i].first * coins[i].second;
        }

        // ������ Ȧ���� ������ ���� �� ����
        if (totalSum % 2 != 0)
        {
            cout << 0 << "\n";

            continue;
        }

        int target = totalSum / 2;

        // DP �迭: dp[i]�� �ݾ� i�� ���� �� �ִ��� ����
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // �ݾ� 0�� �׻� ���� �� ����

        for (auto coin : coins) 
        {
            int value = coin.first;
            int count = coin.second;

            // ������ ���� ������ ����� DP ������Ʈ
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

        // ��ǥ �ݾ�(target)�� ���� �� ������ 1, ������ 0 ���
        cout << dp[target] << "\n";
    }

    return 0;
}