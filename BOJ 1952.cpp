#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
const int MAX_DIR = 4;

typedef struct
{
	int y, x;
}Coord;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[MAX_DIR] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M, N;
	cin >> M >> N;

	bool visited[MAX][MAX] = { false, };
	visited[0][0] = true;

	int result = 0;
	int dir = 0;

	queue<Coord> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		Coord cur = q.front();
		int y = cur.y;
		int x = cur.x;
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			dir = (dir + i) % MAX_DIR;

			int nextY = y + moveDir[dir].y;
			int nextX = x + moveDir[dir].x;

			if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N)
			{
				continue;
			}

			if (visited[nextY][nextX])
			{
				continue;
			}

			// ²ª¾ú´Ù´Â ¶æ
			if (i == 1)
			{
				result++;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });

			break;
		}
	}

	cout << result << "\n";

	return 0;
}