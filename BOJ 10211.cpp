#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) 
    {
        int N;
        cin >> N;

        vector<int> X(N);

        for (int i = 0; i < N; i++)
        {
            cin >> X[i];
        }

        // Kadane's Algorithm to find the maximum subarray sum
        int maxSum = X[0];
        int curSum = X[0];

        for (int i = 1; i < N; i++) 
        {
            curSum = max(X[i], curSum + X[i]);

            maxSum = max(maxSum, curSum);
        }

        cout << maxSum << '\n';
    }

    return 0;
}
