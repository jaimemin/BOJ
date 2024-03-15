#include <iostream>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

const int MAX = 50;

int result = INF;

int N, M;

int board[MAX][MAX];

vector<pair<int, int>> houses;

int getDist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void func(int y, int x, set<pair<int, int>> &s)
{
	if (s.size() == M)
	{
		int dist = 0;

		for (pair<int, int> house : houses)
		{
			int temp = INF;

			for (pair<int, int> chicken : s)
			{
				temp = min(temp, getDist(house, chicken));
			}

			dist += temp;
		}

		result = min(result, dist);

		return;
	}

	if (y < 0 || y >= N || x < 0 || x >= N)
	{
		return;
	}

	for (int i = y; i < N; i++)
	{
		for (int j = (i == y ? x : 0); j < N; j++)
		{
			if (board[i][j] == 2)
			{
				s.insert({ i, j });
				func(j == N - 1 ? i + 1 : i, j == N - 1 ? 0 : j + 1, s);
				s.erase({ i, j });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];

			if (board[y][x] == 1)
			{
				houses.push_back({ y, x });
			}
		}
	}

	set<pair<int, int>> s;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (board[y][x] == 2)
			{
				s.insert({ y, x });
				func(x == N - 1 ? y + 1 : y, x == N - 1 ? 0 : x + 1, s);
				s.erase({ y, x });
			}
		}
	}

	cout << result << "\n";

	return 0;
}
