#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, X;
    cin >> N >> X;

    vector<int> visitors(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> visitors[i];
    }

    // Sliding window to calculate maximum visits in X days
    int curSum = 0;

    for (int i = 0; i < X; i++) 
    {
        curSum += visitors[i];
    }

    int maxSum = curSum;
    int cnt = 1;

    for (int i = X; i < N; i++) 
    {
        curSum += visitors[i] - visitors[i - X];

        if (curSum > maxSum) 
        {
            maxSum = curSum;

            cnt = 1;
        }
        else if (curSum == maxSum) 
        {
            cnt++;
        }
    }

    if (maxSum == 0) 
    {
        cout << "SAD" << '\n';
    }
    else 
    {
        cout << maxSum << '\n';
        cout << cnt << '\n';
    }

    return 0;
}