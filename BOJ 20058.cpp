#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 64;

typedef struct
{
	int y, x;
} Coord;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int N;
int A[MAX][MAX];
bool visited[MAX][MAX];

void rotate(int y, int x, int l)
{
	int tempA[MAX][MAX];
	
	// 기존 2^L * 2^L 격자 복사
	for (int i = y; i < y + (1 << l); i++)
	{
		for (int j = x; j < x + (1 << l); j++)
		{
			tempA[i][j] = A[i][j];
		}
	}

	// 회전시키는 알고리즘
	for (int i = y; i < y + (1 << l); i++)
	{
		for (int j = x; j < x + (1 << l); j++)
		{
			A[j - x + y][y + (1 << l) - (i + 1) + x] = tempA[i][j];
		}
	}
}

void fireStorm(void)
{
	queue<Coord> q;
	
	for (int y = 0; y < (1 << N); y++)
	{
		for (int x = 0; x < (1 << N); x++)
		{
			if (A[y][x] == 0)
			{
				continue;
			}

			int adjacentIceCnt = 0;

			for (int k = 0; k < 4; k++)
			{
				int nextY = y + moveDir[k].y;
				int nextX = x + moveDir[k].x;

				if (nextY < 0 || nextY >= (1 << N) || nextX < 0 || nextX >= (1 << N))
				{
					continue;
				}

				if (A[nextY][nextX])
				{
					adjacentIceCnt++;
				}
			}

			if (adjacentIceCnt < 3)
			{
				q.push({ y, x });
			}
		}
	}

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		A[y][x]--;
	}
}

int getIceSum(void)
{
	int result = 0;

	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			result += A[i][j];
		}
	}

	return result;
}

int BFS(int y, int x)
{
	queue<Coord> q;
	q.push({ y, x });
	visited[y][x] = true;
	
	int cnt = 0;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		cnt++;

		for (int k = 0; k < 4; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			if (nextY < 0 || nextY >= (1 << N) || nextX < 0 || nextX >= (1 << N))
			{
				continue;
			}

			if (visited[nextY][nextX] || A[nextY][nextX] == 0) 
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}
	}

	return cnt;
}

int getLargentComponent(void)
{
	int result = 0;

	for (int y = 0; y < (1 << N); y++)
	{
		for (int x = 0; x < (1 << N); x++)
		{
			if (visited[y][x] || A[y][x] == 0)
			{
				continue;
			}

			result = max(result, BFS(y, x));
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int Q;
	cin >> N >> Q;

	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			cin >> A[i][j];
		}
	}

	for (int q = 0; q < Q; q++)
	{
		int L;
		cin >> L;

		for (int y = 0; y < (1 << N); y += (1 << L))
		{
			for (int x = 0; x < (1 << N); x += (1 << L))
			{
				rotate(y, x, L);
			}
		}

		fireStorm();
	}

	cout << getIceSum() << "\n";
	cout << getLargentComponent() << "\n";

	return 0;
}