#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(const vector<int>& houses, int distance, int C)
{
    int cnt = 1; // 첫 번째 공유기는 항상 첫 번째 집에 설치
    int lastInstalled = houses[0];

    for (int i = 1; i < houses.size(); i++) 
    {
        if (houses[i] - lastInstalled >= distance) 
        {
            cnt++;
            lastInstalled = houses[i];
        }

        if (cnt >= C)
        {
            return true; // 공유기 C개 설치 가능
        }
    }

    return cnt >= C;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    cin >> N >> C;

    vector<int> houses(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end()); // 집 좌표 정렬

    int low = 1, high = houses[N - 1] - houses[0], result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (func(houses, mid, C))
        {
            result = mid; // 가능한 거리 저장
            low = mid + 1; // 더 큰 거리 시도
        }
        else 
        {
            high = mid - 1; // 더 작은 거리 시도
        }
    }

    cout << result << "\n";

    return 0;
}