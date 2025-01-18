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
            return false; // �ʰ� �� false
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
            result = mid; // ������ ���Ѿ� ����
            low = mid + 1; // �� ���� ���Ѿ� Ž��
        }
        else
        {
            high = mid - 1; // �� ���� ���Ѿ� Ž��
        }
    }

    cout << result << "\n";

    return 0;
}