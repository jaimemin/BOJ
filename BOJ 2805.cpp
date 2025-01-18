#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool func(const vector<long long>& trees, long long height, long long M) 
{
    long long total = 0;

    for (const auto& tree : trees) 
    {
        if (tree > height) {
            total += tree - height;
        }

        if (total >= M)
        {
            return true;
        }
    }

    return total >= M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N, M;
    cin >> N >> M;

    vector<long long> trees(N);
    long long maxHeight = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];

        maxHeight = max(maxHeight, trees[i]); // ���� �� ���� ū ����
    }

    long long low = 0, high = maxHeight, result = 0;

    while (low <= high) 
    {
        long long mid = (low + high) / 2;

        if (func(trees, mid, M))
        {
            result = mid; // ������ ����
            low = mid + 1; // �� ���� ���̸� �õ�
        }
        else 
        {
            high = mid - 1; // ���� ���̸� �õ�
        }
    }

    cout << result << "\n";

    return 0;
}