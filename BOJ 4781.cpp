#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 5e3 + 5;

const int CACHE_MAX = 1e4 + 1e2;

int N, C;

double M, P;

pair<int, int> candy[MAX];

int cache[CACHE_MAX];

int func(int cash)
{
	int& result = cache[cash];

	if (result != -1)
	{
		return result;
	}

	result = 0;

	for (int i = 0; i < N; i++)
	{
		if (cash >= candy[i].second)
		{
			result = max(result, candy[i].first + func(cash - candy[i].second));
		}
	}

	return result;
}

int main(void)
{
	while (true)
	{
		cin	>> N >> M;

		if (N == 0 && M == 0.00)
		{
			break;
		}

		memset(cache, -1, sizeof(cache));

		for (int i = 0; i < N; i++)
		{
			cin >> C >> P;

			candy[i] = { C, (int)(P * 100 + 0.5) };
		}

		cout << func((int)(M * 100 + 0.5)) << "\n";
	}

	return 0;
}