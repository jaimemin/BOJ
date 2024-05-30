#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100 + 10;

int N;

long long arr[MAX];

long long cache[MAX][20 + 1];

long long func(int idx, int total)
{
	if (total < 0 || total > 20)
	{
		return 0;
	}

	long long& result = cache[idx][total];

	if (result != -1)
	{
		return result;
	}

	if (idx == N - 2)
	{
		return total == arr[N - 1];
	}

	result = 0;

	result += func(idx + 1, total + arr[idx + 1]);
	result += func(idx + 1, total - arr[idx + 1]);

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	memset(cache, -1, sizeof(cache));

	cout << func(0, arr[0]) << "\n";

	return 0;
}