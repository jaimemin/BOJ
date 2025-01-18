#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(const vector<int>& requests, int cap, int totalBudget)
{
    long long allocated = 0;

    for (int req : requests)
    {
        allocated += min(req, cap);

        if (allocated > totalBudget)
        {
            return false; // 초과 시 false
        }
    }

    return allocated <= totalBudget;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> requests(N);
    int maxRequest = 0;

    for (int i = 0; i < N; i++) 
    {
        cin >> requests[i];

        maxRequest = max(maxRequest, requests[i]);
    }

    int totalBudget;
    cin >> totalBudget;

    int low = 0, high = maxRequest, result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (func(requests, mid, totalBudget)) 
        {
            result = mid; // 가능한 상한액 저장
            low = mid + 1; // 더 높은 상한액 탐색
        }
        else
        {
            high = mid - 1; // 더 낮은 상한액 탐색
        }
    }

    cout << result << "\n";

    return 0;
}