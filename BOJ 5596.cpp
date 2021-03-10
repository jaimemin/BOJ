#include <iostream>
#include <algorithm>
using namespace std;

const int MINGUK = 0;
const int MANSE = 1;
const int MAX = 2;
const int TEST_MAX = 4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int scoreTotals[MAX] = { 0, };

	for (int t = 0; t < MAX; t++)
	{
		for (int i = 0; i < TEST_MAX; i++)
		{
			int score;
			cin >> score;

			scoreTotals[t] += score;
		}
	}

	cout << max(scoreTotals[MINGUK], scoreTotals[MANSE]) << "\n";

	return 0;
}