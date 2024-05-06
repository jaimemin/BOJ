#include <iostream>
using namespace std;

const int MAX = 1e4 + 1e2;

const int INF = 987654321;

int N, K;

int cache[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int i = 1; i < MAX; i++)
	{
		cache[i] = INF;
	}

	for (int i = 0; i < N; i++)
	{
		int coin;
		cin >> coin;

		for (int j = coin; j <= K; j++)
		{
			cache[j] = min(cache[j], 1 + cache[j - coin]);
		}
	}

	cout << (cache[K] == INF ? -1 : cache[K]) << "\n";

	return 0;
}