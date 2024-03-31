#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20 + 2;

const int INF = 987654321;

int result = INF;

int N;

int coins[MAX];

void func(int idx)
{
	if (idx == N)
	{
		int sum = 0;

		// ���� �������� ���� �ľ�
		for (int i = 1; i < (1 << N); i *= 2)
		{
			int temp = 0;

			for (int j = 0; j < N; j++)
			{
				if (i & coins[j])
				{
					temp++;
				}
			}

			sum += min(temp, N - temp);
		}

		result = min(result, sum);

		return;
	}

	// ���� ������ ���� ������ �ʴ� ��� ��� ������� ��
	func(idx + 1);
	coins[idx] = ~coins[idx]; // ��Ʈ����ŷ ����� �̿��ϸ� ������ ������ �� ����
	func(idx + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	// �־��� ���ڿ��� T�� �������� ������ ��Ʈ�� ��ü
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		int bit = 1;

		for (int j = 0; j < N; j++)
		{
			if (s[j] == 'T')
			{
				coins[i] |= bit;
			}

			bit *= 2;
		}
	}

	func(0);

	cout << result << "\n";

	return 0;
}