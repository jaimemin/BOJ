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
		int s, n;
		cin >> s >> n;

		int result = s;

		for (int i = 0; i < n; i++)
		{
			int cnt, price;
			cin >> cnt >> price;

			result += cnt * price;
		}

		cout << result << "\n";
	}

	return 0;
}