#include <iostream>
using namespace std;

long long func(long long N, long long x)
{
    long long cnt = 0;

    for (long long i = 1; i <= N; i++) 
    {
        cnt += min(x / i, N); // x ������ i�� ����� ����
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
            result = mid; // mid�� k��° ���� ���ɼ��� ����
            high = mid - 1; // �� ���� ���� Ž��
        }
        else 
        {
            low = mid + 1; // �� ū ���� Ž��
        }
    }

    cout << result << "\n";

    return 0;
}