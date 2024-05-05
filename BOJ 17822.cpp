#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

const int MAX = 50 + 1;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

int N, M, T;

int X, D, K;

deque<int> dq[MAX];

void turnRullet(void)
{
	for (int x = X; x <= N; x += X)
	{
		for (int k = 0; k < K; k++)
		{
			if (D == 0)
			{
				int temp = dq[x].back();
				dq[x].pop_back();

				dq[x].push_front(temp);
			}
			else
			{
				int temp = dq[x].front();
				dq[x].pop_front();

				dq[x].push_back(temp);
			}
		}
	}
}

bool eraseNumbers(void)
{
	bool erasedNumbers = false;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dq[i][j] == 0)
			{
				continue;
			}

			queue<pair<int, int>> q;
			int value = dq[i][j];
			q.push({ i, j });

			bool visited[MAX][MAX] = { false, };
			visited[i][j] = true;

			vector<pair<int, int>> v;

			while (!q.empty())
			{
				int y = q.front().first;
				int x = q.front().second;
				q.pop();

				v.push_back({ y, x });

				for (int d = 0; d < 4; d++)
				{
					int nextY = y + moveDir[d].y;
					int nextX = x + moveDir[d].x;

					if (nextY == 0 || nextY > N)
					{
						continue;
					}

					if (nextX == -1)
					{
						nextX = M - 1;
					}
					else if (nextX == M)
					{
						nextX = 0;
					}

					if (visited[nextY][nextX])
					{
						continue;
					}

					if (dq[nextY][nextX] == value)
					{
						visited[nextY][nextX] = true;

						q.push({ nextY, nextX });
					}
				}
			}

			if (v.size() >= 2)
			{
				erasedNumbers = true;

				for (int k = 0; k < v.size(); k++)
				{
					int y = v[k].first;
					int x = v[k].second;

					dq[y][x] = 0;
				}
			}
		}
	}

	return erasedNumbers;
}

void changeNumbers(void)
{
	int sum = 0;
	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dq[i][j] == 0)
			{
				continue;
			}

			sum += dq[i][j];
			cnt++;
		}
	}

	if (cnt == 0)
	{
		return;
	}

	double average = (double)sum / cnt;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dq[i][j] == 0)
			{
				continue;
			}

			if (dq[i][j] > average)
			{
				dq[i][j]--;
			}
			else if (dq[i][j] < average)
			{
				dq[i][j]++;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int num;
			cin >> num;

			dq[i].push_back(num);
		}
	}

	for (int t = 0; t < T; t++)
	{
		cin >> X >> D >> K;

		turnRullet();

		bool flag = eraseNumbers();

		if (flag)
		{
			continue;
		}

		changeNumbers();
	}

	int result = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			result += dq[i][j];
		}
	}

	cout << result << "\n";

	return 0;
}