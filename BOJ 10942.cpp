#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 2e3 + 2e2;

int N, M, S, E;

int arr[MAX];

int cache[MAX][MAX];

void init()
{
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			cache[i][i + 1] = 1;
		}
	}

	for (int len = 2; len <= N; len++)
	{
		for (int idx = 1; idx <= N - len; idx++)
		{
			if (arr[idx] == arr[idx + len]
				&& cache[idx + 1][idx + len - 1])
			{
				cache[idx][idx + len] = 1;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];

		cache[i][i] = 1;
	}

	init();

	cin >> M;

	while (M--)
	{
		cin >> S >> E;

		cout << cache[S][E] << "\n";
	}

	return 0;
}