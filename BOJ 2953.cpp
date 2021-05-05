#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5;

typedef struct
{
	int score;
	int contestant;
} Cook;

bool cmp(Cook a, Cook b)
{
	return a.score > b.score;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Cook cooks[MAX];

	for (int i = 1; i <= MAX; i++)
	{
		int sum = 0;

		for (int j = 0; j < 4; j++)
		{
			int score;
			cin >> score;

			sum += score;
		}

		cooks[i - 1] = { sum, i };
	}

	sort(cooks, cooks + MAX, cmp);

	cout << cooks[0].contestant << " " << cooks[0].score << "\n";

	return 0;
}