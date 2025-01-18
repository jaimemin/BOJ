#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = 0;
    int curSum = 0, cnt = 0;

    while (end < N)
    {
        // Expand the window by including arr[end]
        curSum += arr[end];

        // Check if the current sum equals M
        while (curSum > M && start <= end)
        {
            curSum -= arr[start];

            start++;
        }

        if (curSum == M) 
        {
            cnt++;
        }

        end++;
    }

    cout << cnt << '\n';

    return 0;
}