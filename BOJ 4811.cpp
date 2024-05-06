#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 30 + 3;

int N;

long long cache[MAX][MAX * 2];

long long func(int whole, int half)
{
	if (whole == 0 && half == 0)
	{
		return 1;
	}

	long long& result = cache[whole][half];

	if (result != -1)
	{
		return result;
	}

	result = 0;

	if (whole)
	{
		result += func(whole - 1, half + 1);
	}

	if (half)
	{
		result += func(whole, half - 1);
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(cache, -1, sizeof(cache));

	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)
		{
			break;
		}

		cout << func(N, 0) << "\n";
	}

	return 0;
}