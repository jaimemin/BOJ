#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX = 49;
const int COLOR_MAX = 3;

typedef struct
{
	int y, x;
} Coord;

typedef struct
{
	int y, x;
} Dir;

Dir moveOrderDir[4] = { {0, -1}, {1, 0}, {0, 1}, {-1,0} };
Dir moveDir[5] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int N;
int marbleCnt;
int A[MAX][MAX];
int destroyedColors[COLOR_MAX + 1];
vector<Coord> marbleOrders;

void setMarblesByGroup(void)
{
	int tempA[MAX][MAX];

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			tempA[y][x] = A[y][x];
			A[y][x] = 0;
		}
	}

	int cnt;
	int aIdx = 0;

	for (int i = 0; i < marbleOrders.size(); i += cnt)
	{
		if (aIdx == marbleOrders.size())
		{
			break;
		}

		int y = marbleOrders[i].y;
		int x = marbleOrders[i].x;

		if (tempA[y][x] == 0)
		{
			continue;
		}

		int color = tempA[y][x];
		cnt = 1;

		for (int j = i + 1; j < marbleOrders.size(); j++)
		{
			int nextY = marbleOrders[j].y;
			int nextX = marbleOrders[j].x;

			if (tempA[nextY][nextX] != color)
			{
				break;
			}

			cnt++;
		}

		int curY = marbleOrders[aIdx].y;
		int curX = marbleOrders[aIdx].x;
		A[curY][curX] = cnt;

		if (aIdx + 1 < marbleOrders.size())
		{
			int nextY = marbleOrders[aIdx + 1].y;
			int nextX = marbleOrders[aIdx + 1].x;
			A[nextY][nextX] = color;
		}
		else
		{
			break;
		}

		aIdx += 2;
	}
}

void moveMarbles(void)
{
	int tempA[MAX][MAX];

	for (int i = 0; i < marbleOrders.size(); i++)
	{
		int y = marbleOrders[i].y;
		int x = marbleOrders[i].x;

		if (A[y][x])
		{
			continue;
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				tempA[y][x] = A[y][x];
			}
		}

		int cnt = 1;
		int idx;

		for (idx = i + 1; idx < marbleOrders.size(); idx++)
		{
			int nextY = marbleOrders[idx].y;
			int nextX = marbleOrders[idx].x;

			if (tempA[nextY][nextX])
			{
				break;
			}

			cnt++;
		}

		for (int j = i; j < marbleOrders.size() - cnt; j++)
		{
			int curY = marbleOrders[j].y;
			int curX = marbleOrders[j].x;
			int nextY = marbleOrders[j + cnt].y;
			int nextX = marbleOrders[j + cnt].x;

			A[curY][curX] = tempA[nextY][nextX];
			A[nextY][nextX] = 0;
		}
	}
}

void destoryConsecutiveMarbles(void)
{
	bool destroyed = false;

	while (true)
	{
		for (int i = 0; i < marbleOrders.size(); i++)
		{
			int y = marbleOrders[i].y;
			int x = marbleOrders[i].x;

			if (A[y][x] == 0)
			{
				continue;
			}

			int color = A[y][x];
			vector<Coord> consecutiveMarbles;
			consecutiveMarbles.push_back({ y, x });

			for (int j = i + 1; j < marbleOrders.size(); j++)
			{
				int nextY = marbleOrders[j].y;
				int nextX = marbleOrders[j].x;

				if (A[nextY][nextX] != color)
				{
					break;
				}

				consecutiveMarbles.push_back({ nextY, nextX });
			}

			if (consecutiveMarbles.size() >= 4)
			{
				for (Coord coord : consecutiveMarbles)
				{
					int curY = coord.y;
					int curX = coord.x;

					A[curY][curX] = 0;
				}

				destroyedColors[color] += consecutiveMarbles.size();
				destroyed = true;
			}
		}

		if (destroyed == false)
		{
			break;
		}

		destroyed = false;

		moveMarbles();
	}
}

void destoryMarbles(int d, int s)
{
	int y = N / 2;
	int x = N / 2;

	for (int i = 0; i < s; i++)
	{
		y = y + moveDir[d].y;
		x = x + moveDir[d].x;

		A[y][x] = 0;
		marbleCnt--;
	}
}

void setOrder(void)
{
	int y = N / 2;
	int x = N / 2;
	int cnt = 1;
	int dir = 0;
	int order = 1;

	while (1)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < cnt; j++)
			{
				y = y + moveOrderDir[dir].y;
				x = x + moveOrderDir[dir].x;

				marbleOrders.push_back({ y, x });
				marbleCnt++;

				if (y == 0 && x == 0)
				{
					return;
				}
			}

			dir = dir == 3 ? 0 : dir + 1;
		}

		cnt++;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> N >> M;

	setOrder();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	for (int m = 0; m < M; m++)
	{
		int d, s;
		cin >> d >> s;

		destoryMarbles(d, s);
		moveMarbles();
		destoryConsecutiveMarbles();
		setMarblesByGroup();
	}

	int result = 0;

	for (int i = 1; i <= COLOR_MAX; i++)
	{
		result += destroyedColors[i] * i;
	}

	cout << result << "\n";

	return 0;
}