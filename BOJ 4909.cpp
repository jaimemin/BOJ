#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 6;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		vector<int> v(MAX);

		bool allZero = true;

		for (int i = 0; i < MAX; i++)
		{
			cin >> v[i];

			if (v[i])
			{
				allZero = false;
			}
		}

		if (allZero)
		{
			break;
		}

		double sum = 0;

		sort(v.begin(), v.end());

		for (int i = 1; i < MAX - 1; i++)
		{
			sum += v[i];
		}

		printf("%g\n", sum / 4);
	}

	return 0;
}