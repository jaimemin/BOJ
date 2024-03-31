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

		// 행을 뒤집을지 여부 파악
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

	// 열을 뒤집는 경우와 뒤집지 않는 경우 모두 살펴봐야 함
	func(idx + 1);
	coins[idx] = ~coins[idx]; // 비트마스킹 기법을 이용하면 간단히 뒤집을 수 있음
	func(idx + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	// 주어진 문자열을 T를 기준으로 생성한 비트로 대체
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