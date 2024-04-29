#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2 * 10;

const int SPOT_MAX = 33;

const int START = 0;

const int FINISH = 32;

typedef struct
{
	int score;
	int nextIdx[5];
}Spot;

int result = -1;

int dices[MAX / 2];

Spot spots[SPOT_MAX] = {
	{ 0, { 1, 2, 3, 4, 5 } },
	{ 2, { 2, 3, 4, 5, 10 } },
	{ 4, { 3, 4, 5, 10, 11 } },
	{ 6, { 4, 5, 10, 11, 12 } },
	{ 8, { 5, 10, 11, 12, 13 } },
	{ 10, { 6, 7, 8, 9, 25 } },
	{ 13, { 7, 8, 9, 25, 26 } },
	{ 16, { 8, 9, 25, 26, 27 } },
	{ 19, { 9, 25, 26, 27, FINISH } },
	{ 25, { 25, 26, 27, FINISH, FINISH } },
	{ 12, { 11, 12, 13, 14, 17 } },
	{ 14, { 12, 13, 14, 17, 18 } },
	{ 16, { 13, 14, 17, 18, 19 } },
	{ 18, { 14, 17, 18, 19, 20 } },
	{ 20, { 15, 16, 9, 25, 26 } },
	{ 22, { 16, 9, 25, 26, 27 } },
	{ 24, { 9, 25, 26, 27, FINISH } },
	{ 22, { 18, 19, 20, 21, 28 } },
	{ 24, { 19, 20, 21, 28, 29 } },
	{ 26, { 20, 21, 28, 29, 30 } },
	{ 28, { 21, 28, 29, 30, 31 } },
	{ 30, { 22, 23, 24, 9, 25 } },
	{ 28, { 23, 24, 9, 25, 26 } },
	{ 27, { 24, 9, 25, 26, 27 } },
	{ 26, { 9, 25, 26, 27, FINISH } },
	{ 30, { 26, 27, FINISH, FINISH, FINISH } },
	{ 35, { 27, FINISH, FINISH, FINISH, FINISH } },
	{ 40, { FINISH, FINISH, FINISH, FINISH, FINISH } },
	{ 32, { 29, 30, 31, 27, FINISH } },
	{ 34, { 30, 31, 27, FINISH, FINISH } },
	{ 36, { 31, 27, FINISH, FINISH, FINISH } },
	{ 38, { 27, FINISH, FINISH, FINISH, FINISH } },
	{ 0, { FINISH, FINISH, FINISH, FINISH, FINISH } }
};

void func(int pieces)
{
	int scores[4] = { 0, };
	int idx[4] = { 0, };
	int visited[SPOT_MAX] = { 0, };
	visited[START] = 4;

	for (int i = 0; i < 10; i++)
	{
		int currentPiece = pieces & 3;
		pieces /= 4;

		int nextIdx = spots[idx[currentPiece]].nextIdx[dices[i] - 1];

		if (nextIdx != FINISH && visited[nextIdx] > 0)
		{
			return;
		}

		visited[idx[currentPiece]]--;
		visited[nextIdx]++;

		idx[currentPiece] = nextIdx;
		scores[currentPiece] += spots[nextIdx].score;
	}

	int total = 0;

	for (int piece = 0; piece < 4; piece++)
	{
		total += scores[piece];
	}

	result = max(result, total);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		cin >> dices[i];
	}

	for (int pieces = 0; pieces < (1 << MAX); pieces++)
	{
		func(pieces);
	}

	cout << result << "\n";

	return 0;
}