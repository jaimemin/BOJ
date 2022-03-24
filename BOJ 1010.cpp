#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 30 + 3;

int cache[MAX][MAX];

int bino(int n, int r)
{
	if (r == 0 || n == r)
	{
		return 1;
	}

	int &result = cache[n][r];

	if (result != -1)
	{
		return result;
	}

	return result = bino(n - 1, r - 1) + bino(n - 1, r);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	memset(cache, -1, sizeof(cache));

	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N >> M;

		cout << bino(M, N) << "\n";
	}

	return 0;
}