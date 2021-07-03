#include <iostream>
using namespace std;

const int MAX = 12;
const int DICE_MAX = 6;

int main(void)
{
	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++)
	{
		int sum;
		cin >> sum;

		bool visited[MAX + 1] = { false, };

		printf("Case %d:\n", t);

		for (int i = 1; i <= DICE_MAX; i++)
		{
			if (visited[i] || sum - i < 1 || sum-i > DICE_MAX)
			{
				continue;
			}

			visited[i] = true;
			visited[sum - i] = true;

			printf("(%d,%d)\n", i, sum - i);
		}
	}

	return 0;
}