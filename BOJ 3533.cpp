#include <iostream>
using namespace std;

const int MAX = 10;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bool inputs[MAX] = { false, };

	for (int i = 0; i < MAX; i++)
	{
		cin >> inputs[i];
	}

	bool result = (inputs[0] || inputs[1]);

	for (int i = 0; i < MAX; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (i == 0 && j == 1)
			{
				continue;
			}

			result ^= (inputs[i] || inputs[j]);
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			for (int k = j + 1; k < MAX; k++)
			{
				result ^= (inputs[i] || inputs[j] || inputs[k]);
			}
		}
	}

	cout << result << "\n";

	return 0;
}