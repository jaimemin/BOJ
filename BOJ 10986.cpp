#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    vector<long long> prefixSum(N + 1, 0);

    for (int i = 1; i <= N; i++) 
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    unordered_map<int, long long> remainder2cnt;
    remainder2cnt[0] = 1;

    long long cnt = 0;

    for (int i = 1; i <= N; i++) 
    {
        int remainder = prefixSum[i] % M;


        if (remainder2cnt.find(remainder) != remainder2cnt.end())
        {
            cnt += remainder2cnt[remainder];
        }

        remainder2cnt[remainder]++;
    }

    cout << cnt << '\n';

    return 0;
}