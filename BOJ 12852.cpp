#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 1e6 + 1e3;

const int INF = 987654321;

int N;

long long cache[MAX];

void trace(int num)
{
	if (num == 0)
	{
		return;
	}

	cout << num << " ";

	if (num % 3 == 0 
		&& cache[num] == (cache[num / 3] + 1))
	{
		trace(num / 3);
	}
	else if (num % 2 == 0 
		&& cache[num] == (cache[num / 2] + 1))
	{
		trace(num / 2);
	}
	else if (num >= 1
		&& cache[num] == (cache[num - 1] + 1))
	{
		trace(num - 1);
	}
}

long long func(int num)
{
	if (num == 1)
	{
		return cache[num] = 0;
	}

	long long& result = cache[num];

	if (result != -1)
	{
		return result;
	}

	result = INF;

	if (num % 3 == 0)
	{
		result = min(result, 1 + func(num / 3));
	}

	if (num % 2 == 0)
	{
		result = min(result, 1 + func(num / 2));
	}

	result = min(result, 1 + func(num - 1));

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	// memset(cache, -1, sizeof(cache));
	// cout << func(N) << "\n";
	
	fill(cache, cache + MAX, INF);
	cache[1] = 0;

	for (int i = 1; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			cache[i] = min(cache[i], 1 + cache[i / 3]);
		}

		if (i % 2 == 0)
		{
			cache[i] = min(cache[i], 1 + cache[i / 2]);
		}

		cache[i] = min(cache[i], 1 + cache[i - 1]);
	}

	cout << cache[N] << "\n";

	trace(N);

	return 0;
}