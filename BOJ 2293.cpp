#include <iostream>
using namespace std;

const int MAX = 1e5 + 1e2;

int N, K;

int cache[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	cache[0] = 1;

	for (int i = 0; i < N; i++)
	{
		int coin;
		cin >> coin;

		if (coin > 1e4)
		{
			continue;
		}

		for (int j = coin; j <= K; j++)
		{
			cache[j] += cache[j - coin];
		}
	}

	cout << cache[K] << "\n";

	return 0;
}