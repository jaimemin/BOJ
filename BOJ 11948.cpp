#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SCIENCE_MAX = 4;
const int HISTORY_MAX = 2;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> scienceScores(SCIENCE_MAX);

	int result = 0;

	for (int i = 0; i < SCIENCE_MAX; i++)
	{
		cin >> scienceScores[i];
	}

	for (int i = 0; i < HISTORY_MAX; i++)
	{
		int score;
		cin >> score;

		result = max(result, score);
	}

	sort(scienceScores.begin(), scienceScores.end());

	for (int i = 1; i < SCIENCE_MAX; i++)
	{
		result += scienceScores[i];
	}

	cout << result << "\n";

	return 0;
}