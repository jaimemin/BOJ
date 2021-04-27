#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
using namespace std;

const int INF = 987654321;
const int MAX = 20;
const int EMPTY = -2;
const int BLACK = -1;
const int RAINBOW = 0;

typedef struct
{
	int y, x;
} Coord;

typedef struct
{
	Coord baseBlock;
	Coord arr[MAX*MAX];
	int blockGroupSize;
	int rainbowCnt;
} BlockGroup;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[4] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX];

void gravity(void)
{
	// �߷�
	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] <= BLACK)
			{
				continue;
			}

			int y = i;

			while (1)
			{
				if (y == N)
				{
					break;
				}

				int cur = board[y][j];
				int next = board[y + 1][j];

				if (next != EMPTY)
				{
					break;
				}

				board[y + 1][j] = cur;
				board[y][j] = EMPTY;
				y++;
			}
		}
	}
}

void rotateBoard(void)
{
	int tempBoard[MAX][MAX];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tempBoard[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[N - (j + 1)][i] = tempBoard[i][j];
		}
	}
}

BlockGroup getBlockGroup(int y, int x, int color)
{
	BlockGroup tempBlockGroup;
	tempBlockGroup.baseBlock = { INF, INF };
	tempBlockGroup.rainbowCnt = 0;

	int baseColor = board[y][x] == RAINBOW ? color : board[y][x];
	
	int tempBoard[MAX][MAX];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tempBoard[i][j] = board[i][j] == RAINBOW ? color : board[i][j];
		}
	}

	queue<Coord> q;
	q.push({ y, x });
	visited[y][x] = true;
	int arrIdx = 0;

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		// ��������� ��
		if (board[curY][curX] == RAINBOW)
		{
			tempBlockGroup.rainbowCnt++;
		}

		// ���� ����� ������ ����� �ƴ� ��� �߿��� ���� ��ȣ�� ���� ���� ���,
		// �׷��� ����� �������� ���� ��ȣ�� ���� ���� ����̴�.
		if (board[curY][curX] != RAINBOW 
			&& (tempBlockGroup.baseBlock.y > curY
			|| (tempBlockGroup.baseBlock.y == curY && tempBlockGroup.baseBlock.x > curX)))
		{
			tempBlockGroup.baseBlock = { curY, curX };
		}

		// ����� �׷쿡 �߰�
		tempBlockGroup.arr[arrIdx++] = { curY, curX };

		for (int k = 0; k < 4; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			// �� �� ���� ���
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || tempBoard[nextY][nextX] <= BLACK)
			{
				continue;
			}

			// ���� ������ �ƴ϶��
			if (tempBoard[nextY][nextX] != baseColor)
			{
				continue;
			}

			if (visited[nextY][nextX])
			{
				continue;
			}

			visited[nextY][nextX] = true;
			q.push({ nextY, nextX });
		}
	}

	tempBlockGroup.blockGroupSize = arrIdx;
	
	if (tempBlockGroup.rainbowCnt == arrIdx)
	{
		tempBlockGroup.blockGroupSize = 0;
	}

	return tempBlockGroup;
}

int getScore(void)
{
	BlockGroup blockGroup;
	blockGroup.rainbowCnt = 0;
	blockGroup.blockGroupSize = 0;
	blockGroup.baseBlock = { INF, INF };

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] <= BLACK)
			{
				continue;
			}

			// ������ ����� �� ���򸶴� �����Ͽ� ����
			for (int color = 1; color <= M; color++)
			{
				memset(visited, false, sizeof(visited));

				BlockGroup tempBlockGroup = getBlockGroup(y, x, color);

				if (tempBlockGroup.blockGroupSize < 2)
				{
					continue;
				}

				// ũ�Ⱑ ���� ū ��� �׷��� ã�´�
				if (tempBlockGroup.blockGroupSize > blockGroup.blockGroupSize)
				{
					blockGroup = tempBlockGroup;

					continue;
				}

				// �׷��� ��� �׷��� ���� ����� ���Ե� ������ ����� ���� ���� ���� ��� �׷�
				if (tempBlockGroup.blockGroupSize == blockGroup.blockGroupSize)
				{
					if (tempBlockGroup.rainbowCnt > blockGroup.rainbowCnt)
					{
						blockGroup = tempBlockGroup;

						continue;
					}

					// �׷��� ��ϵ� ��������� ���� ����� ���� ���� ū ����, �� �͵� �������̸� ���� ���� ū ���� ã�´�
					if (tempBlockGroup.rainbowCnt == blockGroup.rainbowCnt)
					{
						if (blockGroup.baseBlock.y < tempBlockGroup.baseBlock.y
							|| (blockGroup.baseBlock.y == tempBlockGroup.baseBlock.y
								&& blockGroup.baseBlock.x < tempBlockGroup.baseBlock.x))
						{
							blockGroup = tempBlockGroup;
						}
					}
				}
			}
		}
	}

	// �׷쿡 ���� ����� ������ 2���� ũ�ų� ���ƾ��ϸ�
	if (blockGroup.blockGroupSize < 2)
	{
		return 0;
	}

	for (int i=0; i < blockGroup.blockGroupSize; i++)
	{
		board[blockGroup.arr[i].y][blockGroup.arr[i].x] = EMPTY;
	}

	return blockGroup.blockGroupSize * blockGroup.blockGroupSize;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	int result = 0;

	while (1)
	{
		int score = getScore();

		if (score == 0)
		{
			break;
		}

		result += score;

		gravity();
		rotateBoard();
		gravity();
	}

	cout << result << "\n";

	return 0;
}