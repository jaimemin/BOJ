#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

const int MAX = 12 + 1;

typedef struct
{
	int y, x;
} Dir;

Dir moveDir[5] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

int N, K;

int board[MAX][MAX];

stack<int> pieces[MAX][MAX];

map<int, pair<int, pair<int, int>>> idx2piece;

bool outOfBounds(int y, int x)
{
	return y < 1 || y > N || x < 1 || x > N;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			cin >> board[y][x];
		}
	}

	for (int k = 1; k <= K; k++)
	{
		int y, x, d;
		cin >> y >> x >> d;

		idx2piece[k] = { y, { x, d } };
		pieces[y][x].push(k);
	}

	int turn = 1;

	while (true)
	{
		for (int k = 1; k <= K; k++)
		{
			int y = idx2piece[k].first;
			int x = idx2piece[k].second.first;
			int dir = idx2piece[k].second.second;

			int nextY = y + moveDir[dir].y;
			int nextX = x + moveDir[dir].x;
			vector<int> v;
			bool blue = false;

			if (outOfBounds(nextY, nextX) || board[nextY][nextX] == 2)
			{
				blue = true;
				dir = dir < 3 ? 3 - dir : 7 - dir;
				nextY = y + moveDir[dir].y;
				nextX = x + moveDir[dir].x;

				if (outOfBounds(nextY, nextX) || board[nextY][nextX] == 2)
				{
					idx2piece[k] = { y, {x, dir} };

					continue;
				}
			}

			if (board[nextY][nextX] == 1)
			{
				while (pieces[y][x].top() != k)
				{
					v.push_back(pieces[y][x].top());

					pieces[y][x].pop();
				}

				v.push_back(pieces[y][x].top());
				pieces[y][x].pop();

				for (int piece : v)
				{
					pieces[nextY][nextX].push(piece);
					idx2piece[piece] = { nextY, {nextX, idx2piece[piece].second.second} };
				}
			}
			else if (board[nextY][nextX] == 0)
			{
				while (pieces[y][x].top() != k)
				{
					v.push_back(pieces[y][x].top());

					pieces[y][x].pop();
				}

				v.push_back(pieces[y][x].top());
				pieces[y][x].pop();

				for (int i = v.size() - 1; i >= 0; i--)
				{
					pieces[nextY][nextX].push(v[i]);
					idx2piece[v[i]] = { nextY, {nextX, idx2piece[v[i]].second.second} };
				}
			}

			if (blue)
			{
				idx2piece[k] = { nextY, {nextX, dir} };
			}

			if (!outOfBounds(nextY, nextX) 
				&& pieces[nextY][nextX].size() >= 4)
			{
				cout << turn << "\n";
				
				exit(0);
			}
		}

		if (++turn > 1e3)
		{
			break;
		}
	}

	cout << -1 << "\n";

	return 0;
}