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
	// 중력
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

		// 무지개블록 수
		if (board[curY][curX] == RAINBOW)
		{
			tempBlockGroup.rainbowCnt++;
		}

		// 기준 블록은 무지개 블록이 아닌 블록 중에서 행의 번호가 가장 작은 블록,
		// 그러한 블록이 여러개면 열의 번호가 가장 작은 블록이다.
		if (board[curY][curX] != RAINBOW 
			&& (tempBlockGroup.baseBlock.y > curY
			|| (tempBlockGroup.baseBlock.y == curY && tempBlockGroup.baseBlock.x > curX)))
		{
			tempBlockGroup.baseBlock = { curY, curX };
		}

		// 블록을 그룹에 추가
		tempBlockGroup.arr[arrIdx++] = { curY, curX };

		for (int k = 0; k < 4; k++)
		{
			int nextY = curY + moveDir[k].y;
			int nextX = curX + moveDir[k].x;

			// 갈 수 없는 블록
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || tempBoard[nextY][nextX] <= BLACK)
			{
				continue;
			}

			// 같은 색깔이 아니라면
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

			// 무지개 블록을 각 색깔마다 지정하여 진행
			for (int color = 1; color <= M; color++)
			{
				memset(visited, false, sizeof(visited));

				BlockGroup tempBlockGroup = getBlockGroup(y, x, color);

				if (tempBlockGroup.blockGroupSize < 2)
				{
					continue;
				}

				// 크기가 가장 큰 블록 그룹을 찾는다
				if (tempBlockGroup.blockGroupSize > blockGroup.blockGroupSize)
				{
					blockGroup = tempBlockGroup;

					continue;
				}

				// 그러한 블록 그룹이 여러 개라면 포함된 무지개 블록의 수가 가장 많은 블록 그룹
				if (tempBlockGroup.blockGroupSize == blockGroup.blockGroupSize)
				{
					if (tempBlockGroup.rainbowCnt > blockGroup.rainbowCnt)
					{
						blockGroup = tempBlockGroup;

						continue;
					}

					// 그러한 블록도 여러개라면 기준 블록의 행이 가장 큰 것을, 그 것도 여러개이면 열이 가장 큰 것을 찾는다
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

	// 그룹에 속한 블록의 개수는 2보다 크거나 같아야하며
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