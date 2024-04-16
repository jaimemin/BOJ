#include <iostream>
#include <deque>
using namespace std;

const int MAX = 100 + 1;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int N, K, L;

bool apples[MAX][MAX];

bool board[MAX][MAX];

char turns[MAX * MAX];

void init()
{
	for (int i = 0; i < MAX * MAX; i++)
	{
		turns[i] = ' ';
	}
}

int main(void)
{
	init();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int k = 0; k < K; k++)
	{
		int y, x;
		cin >> y >> x;

		apples[y][x] = true;
	}

	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int X;
		char C;
		cin >> X >> C;

		turns[X] = C;
	}

	pair<int, int> pos = { 1, 1 };
	deque<pair<int, int>> snake;
	snake.push_back(pos);
	board[pos.first][pos.second] = true;
	int dir = 0;
	int time = 1;

	while (true)
	{
		pair<int, int> next = { pos.first + moveDir[dir].y, pos.second + moveDir[dir].x };

		if (next.first > N || next.first <= 0 || next.second > N || next.second <= 0)
		{
			break;
		}

		if (board[next.first][next.second])
		{
			break;
		}

		if (apples[next.first][next.second])
		{
			apples[next.first][next.second] = false;
		}
		else
		{
			pair<int, int> tail = snake.front();
			board[tail.first][tail.second] = false;
			snake.pop_front();
		}

		snake.push_back(next);
		board[next.first][next.second] = true;
		char c = turns[time++];

		if (c != ' ')
		{
			dir = c == 'D' ? (dir + 1) % 4 : (dir + 3) % 4;
		}

		pos = next;
	}

	cout << time << "\n";

	return 0;
}