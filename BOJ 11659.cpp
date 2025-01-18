#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> numbers(N + 1, 0); // 1-based indexing
    vector<int> prefixSum(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> numbers[i];

        prefixSum[i] = prefixSum[i - 1] + numbers[i];
    }

    for (int q = 0; q < M; q++)
    {
        int i, j;
        cin >> i >> j;

        cout << prefixSum[j] - prefixSum[i - 1] << '\n';
    }

    return 0;
}