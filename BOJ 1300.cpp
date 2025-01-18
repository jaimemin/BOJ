#include <iostream>
using namespace std;

long long func(long long N, long long x)
{
    long long cnt = 0;

    for (long long i = 1; i <= N; i++) 
    {
        cnt += min(x / i, N); // x 이하인 i의 배수의 개수
    }

    return cnt;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, k;
    cin >> N >> k;

    long long low = 1, high = N * N, result = 0;

    while (low <= high) 
    {
        long long mid = (low + high) / 2;

        if (func(N, mid) >= k) {
            result = mid; // mid가 k번째 값일 가능성이 있음
            high = mid - 1; // 더 작은 값을 탐색
        }
        else 
        {
            low = mid + 1; // 더 큰 값을 탐색
        }
    }

    cout << result << "\n";

    return 0;
}