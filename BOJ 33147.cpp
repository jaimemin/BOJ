#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) 
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, K;
    cin >> N >> K;

    vector<long long> A(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    long long g = gcd(N, K);

    for (long long start = 0; start < g; start++) 
    {
        vector<long long> indices;

        for (long long step = 0; step < N / g; step++)
        {
            long long idx = (start + step * K) % N;

            indices.push_back(idx);
        }

        sort(indices.begin(), indices.end());

        vector<long long> values;
        values.reserve(indices.size());

        for (auto& idx : indices)
        {
            values.push_back(A[idx]);
        }

        sort(values.begin(), values.end());

        for (int i = 0; i < indices.size(); i++)
        {
            if (indices[i] != values[i])
            {
                cout << "NO\n";

                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}
