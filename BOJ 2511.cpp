#include <iostream>
using namespace std;

const int MAX = 10;
const int WIN_SCORE = 3;
const int DRAW_SCORE = 1;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A[10];

	for (int i = 0; i < MAX; i++)
	{
		cin >> A[i];
	}

	char lastWinner = 'D';
	int AScore = 0, BScore = 0;

	for (int i = 0; i < MAX; i++)
	{
		int B;
		cin >> B;

		if (A[i] > B)
		{
			AScore += WIN_SCORE;

			lastWinner = 'A';
		}
		else if (B > A[i])
		{
			BScore += WIN_SCORE;

			lastWinner = 'B';
		}
		else
		{
			AScore += DRAW_SCORE;
			BScore += DRAW_SCORE;
		}
	}

	cout << AScore << " " << BScore << "\n";

	if (AScore > BScore)
	{
		cout << "A\n";
	}
	else if (AScore < BScore)
	{
		cout << "B\n";
	}
	else
	{
		cout << lastWinner << "\n";
	}

	return 0;
}