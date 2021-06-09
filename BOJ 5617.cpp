#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 3;

enum Type
{
	TRIANGLE=0,
	ANGLE,
	ACUTE,
	OBTUSE
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int result[4] = { 0, };

	while (1)
	{
		vector<int> sides(MAX);

		for (int i = 0; i < MAX; i++)
		{
			cin >> sides[i];
		}

		sort(sides.begin(), sides.end());

		if (sides[0] + sides[1] <= sides[2])
		{
			break;
		}

		// 弊成 伙阿屈
		result[TRIANGLE]++;

		// 流阿伙阿屈
		if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2])
		{
			result[ANGLE]++;

			continue;
		}

		// 抗阿
		if (sides[0] * sides[0] + sides[1] * sides[1] > sides[2] * sides[2])
		{
			result[ACUTE]++;

			continue;
		}

		// 敌阿
		result[OBTUSE]++;
	}

	for (int i = 0; i < 4; i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}
