#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> A(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    vector<int> B(M);

    for (int j = 0; j < M; j++)
    {
        cin >> B[j];
    }

    sort(A.begin(), A.end());

    for (int j = 0; j < M; j++) 
    {
        int skill = B[j];
        int count = upper_bound(A.begin(), A.end(), skill) - A.begin();

        if (count == 0)
        {
            cout << 0 << " ";

            continue;
        }

        int low = 1;
        int high = 1000;
        int answer = 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            long long req = 3LL * mid * (mid - 1) + 1;

            if (req <= count) 
            {
                answer = mid;

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << answer << " ";
    }

    return 0;
}