#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(const vector<int>& houses, int distance, int C)
{
    int cnt = 1; // ù ��° ������� �׻� ù ��° ���� ��ġ
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
            return true; // ������ C�� ��ġ ����
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

    sort(houses.begin(), houses.end()); // �� ��ǥ ����

    int low = 1, high = houses[N - 1] - houses[0], result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (func(houses, mid, C))
        {
            result = mid; // ������ �Ÿ� ����
            low = mid + 1; // �� ū �Ÿ� �õ�
        }
        else 
        {
            high = mid - 1; // �� ���� �Ÿ� �õ�
        }
    }

    cout << result << "\n";

    return 0;
}