#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;

		cout << "Case " << t << ": ";

		cout << n - 1 << " ";

		for (int i = n; i >= 0; i--)
		{
			int num;
			cin >> num;

			if (i == 0)
			{
				continue;
			}

			cout << i * num << " ";
		}

		cout << "\n";
	}

	return 0;
}