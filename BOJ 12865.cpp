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

	for (int i = 0; i < N; i++)
	{
		int W, V;
		cin >> W >> V;

		for (int j = K; j >= W; j--)
		{
			cache[j] = max(cache[j], V + cache[j - W]);
		}
	}

	cout << cache[K] << "\n";

	return 0;
}