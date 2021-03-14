#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5;
const int MIN_SCORE = 40;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;

	for (int i = 0; i < MAX; i++)
	{
		int score;
		cin >> score;

		sum += max(score, MIN_SCORE);
	}

	int average = sum / MAX;

	cout << average << "\n";

	return 0;
}