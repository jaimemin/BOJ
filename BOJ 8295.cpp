#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, p;
	cin >> n >> m >> p;

	long long result = 0;

	for (long long row = 1; row <= n; row++)
	{
		for (long long col = 1; col <= m; col++)
		{
			long long parameter = (row + col) * 2;

			if (parameter >= p)
			{
				result += (n - row + 1) * (m - col + 1) * 1LL;
			}
		}
	}

	cout << result << "\n";

	return 0;
}