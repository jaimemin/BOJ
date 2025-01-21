#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> memory(N); // �� ���� �޸� ��뷮
    vector<int> cost(N);   // �� ���� ��Ȱ��ȭ ���

    for (int i = 0; i < N; i++) 
    {
        cin >> memory[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    // �ִ� ����� �� ���
    int maxCost = 0;

    for (int i = 0; i < N; ++i) 
    {
        maxCost += cost[i];
    }

    // DP �迭: dp[cost] = Ȯ�� ������ �ִ� �޸�
    vector<int> dp(maxCost + 1, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = maxCost; j >= cost[i]; j--) 
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    // �ּ� ��� ã��
    int result = maxCost;

    for (int i = 0; i <= maxCost; i++) 
    {
        if (dp[i] >= M) 
        {
            result = i;

            break;
        }
    }

    cout << result << "\n";

    return 0;
}