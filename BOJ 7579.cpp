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

    vector<int> memory(N); // 각 앱의 메모리 사용량
    vector<int> cost(N);   // 각 앱의 비활성화 비용

    for (int i = 0; i < N; i++) 
    {
        cin >> memory[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    // 최대 비용의 합 계산
    int maxCost = 0;

    for (int i = 0; i < N; ++i) 
    {
        maxCost += cost[i];
    }

    // DP 배열: dp[cost] = 확보 가능한 최대 메모리
    vector<int> dp(maxCost + 1, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = maxCost; j >= cost[i]; j--) 
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    // 최소 비용 찾기
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