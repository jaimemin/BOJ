#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 16 + 1;

const int INF = 987654321;

int N;

int result = INF;

int W[MAX][MAX];

int cache[MAX][1 << MAX];

int func(int cur, int visited)
{
	if (visited == (1 << N) - 1)
	{
		return W[cur][0] != 0 ? W[cur][0] : INF;
	}

	int& result = cache[cur][visited];

	if (result != -1)
	{
		return result;
	}

	result = INF;

	for (int next = 0; next < N; next++)
	{
		if (visited & (1 << next)
			|| W[cur][next] == 0)
		{
			continue;
		}

		result = min(result, W[cur][next] + func(next, visited + (1 << next)));
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));

	cout << func(0, 1) << "\n";

	return 0;
}