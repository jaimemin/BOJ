#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e5 + 1e2;

int cache[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	memset(cache, -1, sizeof(cache));
	cache[2] = cache[5] = 1;

	for (int i = 3; i < n + 1; i++) 
	{
		if (cache[i - 2] != -1)
		{
			cache[i] = cache[i - 2] + 1;
		}

		if (i <= 5)
		{
			continue;
		}

		if (cache[i - 5] != -1)
		{
			cache[i] = min(cache[i], cache[i - 5] + 1);
		}
	}

	cout << cache[n] << "\n";

	return 0;
}