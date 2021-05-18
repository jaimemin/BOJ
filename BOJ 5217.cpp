#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;

		cout << "Pairs for " << n << ":";

		int cnt = 0;

		for (int i = 1; i < n / 2 + 1; i++)
		{
			if (i == n - i || n - i == 0)
			{
				continue;
			}

			if (cnt++)
			{
				cout << ",";
			}

			cout << " " << i << " " << n - i;
		}

		cout << "\n";
	}

	return 0;
}