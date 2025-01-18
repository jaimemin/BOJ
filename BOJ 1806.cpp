#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, S;
    cin >> N >> S;

    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int minLength = N + 1;
    int start = 0, end = 0, currentSum = 0;

    while (end < N)
    {
        // Expand the window by including arr[end]
        currentSum += arr[end];

        // Shrink the window from the start as long as the condition is satisfied
        while (currentSum >= S)
        {
            minLength = min(minLength, end - start + 1);

            currentSum -= arr[start];
            start++;
        }

        end++;
    }

    // If no valid subarray was found
    if (minLength == N + 1) 
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << minLength << '\n';
    }

    return 0;
}