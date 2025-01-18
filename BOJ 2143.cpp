#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long T;
    cin >> T;

    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
    }

    int m;
    cin >> m;

    vector<int> B(m);

    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    // Generate all subarray sums of A
    unordered_map<long long, int> sumA2cnt;

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;

        for (int j = i; j < n; j++) 
        {
            sum += A[j];

            sumA2cnt[sum]++;
        }
    }

    // Count all subarray sums of B that satisfy the condition
    long long cnt = 0;

    for (int i = 0; i < m; i++) 
    {
        long long sum = 0;

        for (int j = i; j < m; j++) 
        {
            sum += B[j];

            if (sumA2cnt.find(T - sum) != sumA2cnt.end())
            {
                cnt += sumA2cnt[T - sum];
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}