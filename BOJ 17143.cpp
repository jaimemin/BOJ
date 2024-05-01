#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;

typedef struct
{
	int r, c, s, d, z;
	bool caught;
} Shark;

int R, C, M;

int board[MAX][MAX];

Shark sharks[MAX * MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		r--, c--;

		board[r][c] = i;
		sharks[i] = { r, c, s % (2 * (d <= 2 ? (R - 1) : (C - 1))), d, z, false };
	}

	int result = 0;

	for (int cur = 0; cur < C; cur++)
	{
		// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다
		for (int y = 0; y < R; y++)
		{
			if (board[y][cur])
			{
				result += sharks[board[y][cur]].z;
				sharks[board[y][cur]].caught = true;

				break;
			}
		}

		memset(board, 0, sizeof(board));

		// 상어가 이동한다
		for (int i = 1; i <= M; i++)
		{
			if (sharks[i].caught)
			{
				continue;
			}

			for (int j = 0; j < sharks[i].s;)
			{
				switch (sharks[i].d)
				{
				case 1:
				case 2:
					if ((sharks[i].d == 1 && sharks[i].r == 0)
						|| (sharks[i].d == 2 && sharks[i].r == R - 1))
					{
						sharks[i].d = 3 - sharks[i].d;

						continue;
					}

					sharks[i].d == 1 ? sharks[i].r-- : sharks[i].r++;
					j++;

					break;
				case 3:
				case 4:
					if ((sharks[i].d == 3 && sharks[i].c == C - 1)
						|| (sharks[i].d == 4 && sharks[i].c == 0))
					{
						sharks[i].d = 7 - sharks[i].d;

						continue;
					}

					sharks[i].d == 3 ? sharks[i].c++ : sharks[i].c--;
					j++;

					break;
				}
			}
		}

		for (int i = 1; i <= M; i++)
		{
			if (sharks[i].caught)
			{
				continue;
			}

			int r = sharks[i].r;
			int c = sharks[i].c;

			if (board[r][c])
			{
				if (sharks[board[r][c]].z > sharks[i].z)
				{
					sharks[i].caught = true;
				}
				else
				{
					sharks[board[r][c]].caught = true;
					board[r][c] = i;
				}
			}
			else
			{
				board[r][c] = i;
			}
		}
	}

	cout << result << "\n";

	return 0;
}