#include <iostream>
using namespace std;

typedef struct
{
	int three, two, one;
}Score;

int getScore(Score score)
{
	int result = score.three * 3 + score.two * 2 + score.one;

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Score Apples, Bananas;
	cin >> Apples.three >> Apples.two >> Apples.one;
	cin >> Bananas.three >> Bananas.two >> Bananas.one;

	int appleScore = getScore(Apples);
	int bananaScore = getScore(Bananas);

	if (appleScore > bananaScore)
	{
		cout << "A\n";
	}
	else if (appleScore < bananaScore)
	{
		cout << "B\n";
	}
	else
	{
		cout << "T\n";
	}

	return 0;
}