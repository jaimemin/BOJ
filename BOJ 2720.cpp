#include <iostream>
using namespace std;

const int MAX = 4;
const int changeValue[MAX] = { 25, 10, 5, 1 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int C;
		cin >> C;

		int result[MAX] = { 0, 0, 0, 0 };

		while (C)
		{
			for (int i = 0; i < MAX; i++)
			{
				if (C - changeValue[i] >= 0)
				{
					result[i]++;
					C -= changeValue[i];

					break;
				}
			}
		}

		for (int i = 0; i < MAX; i++)
		{
			cout << result[i] << " ";
		}

		cout << "\n";
	}

	return 0;
}