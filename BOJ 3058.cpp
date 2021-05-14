#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 7;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		vector<int> v(MAX);

		for (int i = 0; i < MAX; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		int sum = 0;
		int minEven = -1;

		for (int i = 0; i <MAX; i++)
		{
			if (v[i] % 2)
			{
				continue;
			}

			if (minEven == -1)
			{
				minEven = v[i];
			}

			sum += v[i];
		}

		cout << sum << " " << minEven << "\n";
	}

	return 0;
}