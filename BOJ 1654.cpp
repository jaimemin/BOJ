#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(const vector<long long>& cables, long long length, long long N) 
{
    long long cnt = 0;

    for (const auto& cable : cables)
    {
        cnt += cable / length; // 현재 길이로 자를 수 있는 랜선 개수

        if (cnt >= N)
        {
            return true; // 필요한 랜선 개수를 이미 만족하면 바로 true 반환
        }
    }

    return cnt >= N;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long K, N;
    cin >> K >> N;

    vector<long long> cables(K);
    long long maxCableLength = 0;

    for (int i = 0; i < K; i++)
    {
        cin >> cables[i];

        maxCableLength = max(maxCableLength, cables[i]); // 가장 긴 랜선 길이 저장
    }

    long long low = 1, high = maxCableLength, result = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (func(cables, mid, N))
        {
            result = mid; // 현재 길이로 만들 수 있으므로 저장
            low = mid + 1; // 더 긴 랜선 길이를 시도
        }
        else 
        {
            high = mid - 1; // 더 짧은 랜선 길이를 시도
        }
    }

    cout << result << "\n";

    return 0;
}