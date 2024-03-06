#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		map<string, int> m;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			string name, type;
			cin >> name >> type;

			m[type]++;
		}

		long long result = 1;

		for (auto c : m)
		{
			result *= (c.second + 1) * 1LL;
		}

		cout << result - 1 << "\n";
	}

	return 0;
}