#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++)
	{
		long long n, m;
		cin >> n >> m;

		long long sum = m * (m + 1) / 2;

		if (n < 0)
		{
			sum -= abs(n) * (abs(n) + 1) / 2;
		}
		else if (n > 1)
		{
			sum -= (n - 1)*(n) / 2;
		}

		cout << "Scenario #" << t << ":\n";
		cout << sum << "\n\n";
	}

	return 0;
}