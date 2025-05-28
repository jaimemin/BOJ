#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getCount(vector<int>& arr, int limit) 
{
    int cnt = 0;
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        if (arr[left] == 0) 
        {
            left++;

            continue;
        }

        if (arr[right] == 0)
        {
            right--;

            continue;
        }

        if (arr[left] + arr[right] <= limit)
        {
            cnt++;
            left++;
        }

        right--;
    }

    return cnt;
}

int find(vector<int>& arr, int limit, int maxPairs)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int pos = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int saved = arr[mid];

        arr[mid] = 0;
        int newCnt = getCount(arr, limit);
        arr[mid] = saved;

        if (newCnt < maxPairs)
        {
            low = mid + 1;
        }
        else
        {
            pos = mid;

            high = mid - 1;
        }
    }

    return (pos < n ? arr[pos] : limit);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> sheep(N), wolves(M);

    for (int i = 0; i < N; i++)
    {
        cin >> sheep[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> wolves[i];
    }

    sort(sheep.begin(), sheep.end());
    sort(wolves.begin(), wolves.end());

    int maxSheepPairs = getCount(sheep, K);
    int maxWolfPairs = getCount(wolves, K);
    int minSheepSingle = find(sheep, K, maxSheepPairs);
    int minWolfSingle = find(wolves, K, maxWolfPairs);
    int totalPens = (N - maxSheepPairs) + (M - maxWolfPairs);

    if (minSheepSingle + minWolfSingle <= K)
    {
        totalPens--;
    }

    cout << totalPens << "\n";

    return 0;
}
