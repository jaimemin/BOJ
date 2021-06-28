#include <iostream>
#include <string>
using namespace std;

const int MIN = 100;
const int MAX = 999;
const int OMIT_MOD = 111;

bool func(int i, int j)
{
	return (i * (j % 100) == (i / 10) * j) && (i % 10 == j / 100);
}

int main(void)
{
	for (int i = MIN; i <= MAX; i++)
	{
		for (int j = MIN; j <= MAX; j++)
		{
			if (i % OMIT_MOD == 0 && j % OMIT_MOD == 0)
			{
				continue;
			}

			if (func(i, j))
			{
				printf("%d / %d = %d / %d\n", i, j, i / 10, j % 100);
			}
		}
	}

	return 0;
}