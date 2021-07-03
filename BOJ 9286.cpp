#include <iostream>
using namespace std;

const int MAX = 6;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;

		cout << "Case " << i << ":\n";

		for (int j = 0; j < m; j++)
		{
			int grade;
			cin >> grade;

			if (grade == MAX)
			{
				continue;
			}

			cout << ++grade << "\n";
		}
	}

	return 0;
}