#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> K(N + 1);

    for (int i = 1; i <= N; i++) 
    {
        cin >> K[i];
    }

    vector<double> dp(N + 1, 0.0);
    dp[0] = 0.0;

    vector<double> prefix(N + 1, 0.0);
    prefix[0] = 0.0;

    for (int x = 1; x <= N; x++) 
    {
        double sumPrev = 0.0;

        if (x - K[x] - 1 >= 0)
        {
            sumPrev = prefix[x - 1] - prefix[x - K[x] - 1];
        }
        else
        {
            sumPrev = prefix[x - 1];
        }

        dp[x] = 1.0 + sumPrev / K[x];
        prefix[x] = prefix[x - 1] + dp[x];
    }

    cout << fixed << setprecision(10) << dp[N] << "\n";

    return 0;
}