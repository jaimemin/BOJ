#include <iostream>
using namespace std;

const int MAX = 1e4 + 1e2;

int T, N;

int cache[MAX];

void init()
{
	cache[0] = 1;

	for (int k = 1; k <= 3; k++)
	{
		for (int i = 1; i <= 1e4; i++)
		{
			if (i >= k)
			{
				cache[i] += cache[i - k];
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	
	init();

	while (T--)
	{
		int N;
		cin >> N;

		cout << cache[N] << "\n";
	}

	return 0;
}