#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 3;

int main(void)
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int sides[MAX];
		cin >> sides[0] >> sides[1] >> sides[2];

		sort(sides, sides + MAX);

		printf("Case #%d: ", t);

		if (sides[0] + sides[1] <= sides[2])
		{
			printf("invalid!\n");

			continue;
		}

		if (sides[0] != sides[1] && sides[1] != sides[2] && sides[2] != sides[0])
		{
			printf("scalene\n");

			continue;
		}

		if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[0])
		{
			printf("equilateral\n");

			continue;
		}

		printf("isosceles\n");
	}

	return 0;
}