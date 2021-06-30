#include <iostream>
using namespace std;

const int MAX = 21252;

const int PHYSICAL_MOD = 23;
const int EMOTIONAL_MOD = 28;
const int INTELLECTUAL_MOD = 33;

const int MIN_PHYSICAL_OVER_YEAR = 23 * 16;
const int MIN_EMOTIONAL_OVER_YEAR = 28 * 14;
const int MIN_INTELLECTUAL_OVER_YEAR = 33 * 12;

int main(void)
{
	for (int day = 1; ; day++)
	{
		int p, e, i, d;
		cin >> p >> e >> i >> d;

		if (p == -1 && e == -1 && i == -1 && d == -1)
		{
			break;
		}

		p = (p + (MIN_PHYSICAL_OVER_YEAR - d)) % PHYSICAL_MOD;
		e = (e + (MIN_EMOTIONAL_OVER_YEAR - d)) % EMOTIONAL_MOD;
		i = (i + (MIN_INTELLECTUAL_OVER_YEAR - d)) % INTELLECTUAL_MOD;

		int visited[MAX + 1] = { 0, };

		for (int idx = p; idx <= MAX; idx += PHYSICAL_MOD)
		{
			visited[idx]++;
		}

		for (int idx = e; idx <= MAX; idx += EMOTIONAL_MOD)
		{
			visited[idx]++;
		}

		for (int idx = i; idx <= MAX; idx += INTELLECTUAL_MOD)
		{
			visited[idx]++;
		}

		int result = 1;

		for (int idx = 1; idx <= MAX; idx++)
		{
			if (visited[idx] == 3)
			{
				result = idx;

				break;
			}
		}

		printf("Case %d: the next triple peak occurs in %d days.\n", day, result);
	}

	return 0;
}