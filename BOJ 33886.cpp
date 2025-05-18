#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> A(N + 1);

    for (int i = 1; i <= N; i++) 
    {
        cin >> A[i];
    }

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= i; j++) 
        {
            int length = i - j + 1;

            if (length <= A[j])
            {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[N] << "\n";

    return 0;
}