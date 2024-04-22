#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;

int N;

long long cache[MAX];

long long func(int idx)
{
	if (idx == 0)
	{
		return 0;
	}

	long long& result = cache[idx];

	if (result != -1)
	{
		return result;
	}

	result = 1 + func(idx - 1);

	if (idx >= 3)
	{
		for (int i = 1; i < idx - 2; i++)
		{
			result = max(result, func((idx - 2) - i) * (i + 1));
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	memset(cache, -1, sizeof(cache));

	cout << func(N) << "\n";

	return 0;
}