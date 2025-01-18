#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(const vector<long long>& cables, long long length, long long N) 
{
    long long cnt = 0;

    for (const auto& cable : cables)
    {
        cnt += cable / length; // ���� ���̷� �ڸ� �� �ִ� ���� ����

        if (cnt >= N)
        {
            return true; // �ʿ��� ���� ������ �̹� �����ϸ� �ٷ� true ��ȯ
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

        maxCableLength = max(maxCableLength, cables[i]); // ���� �� ���� ���� ����
    }

    long long low = 1, high = maxCableLength, result = 0;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if (func(cables, mid, N))
        {
            result = mid; // ���� ���̷� ���� �� �����Ƿ� ����
            low = mid + 1; // �� �� ���� ���̸� �õ�
        }
        else 
        {
            high = mid - 1; // �� ª�� ���� ���̸� �õ�
        }
    }

    cout << result << "\n";

    return 0;
}