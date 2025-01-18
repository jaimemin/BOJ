#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> table(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> prefixSum(N + 1, vector<int>(N + 1, 0));

    // 표 데이터 입력 및 2차원 누적 합 계산
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) 
        {
            cin >> table[i][j];

            prefixSum[i][j] = table[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    // 쿼리 처리
    for (int q = 0; q < M; q++) 
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = prefixSum[x2][y2]
            - prefixSum[x1 - 1][y2]
            - prefixSum[x2][y1 - 1]
            + prefixSum[x1 - 1][y1 - 1];

        cout << result << '\n';
    }

    return 0;
}