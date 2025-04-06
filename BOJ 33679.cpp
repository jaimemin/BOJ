#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxScore(vector<int>& bullets) 
{
    int n = bullets.size();
    int best = 0;

    for (int start = 0; start < n; start++)
    {
        vector<int> seq(n);

        for (int i = 0; i < n; i++)
        {
            seq[i] = bullets[(start + i) % n];
        }

        vector<int> dp(n, 1);
        int localMax = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++) 
            {
                if (seq[j] < seq[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            localMax = max(localMax, dp[i]);
        }

        best = max(best, localMax);
    }

    return best;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    int scoreA = getMaxScore(A);
    int scoreB = getMaxScore(B);

    if (scoreA > scoreB)
    {
        cout << "YJ Win!";
    }
    else if (scoreA < scoreB)
    {
        cout << "HG Win!";
    }
    else
    {
        cout << "Both Win!";
    }

    return 0;
}