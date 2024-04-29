#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 1e3 + 1;

int T;

string gears[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> gears[i];
	}

	int K;
	cin >> K;

	for (int k = 0; k < K; k++)
	{
		int gear, dir;
		cin >> gear >> dir;

		queue<pair<int, int>> q;
		q.push({ gear, dir });

		int cur = gear;
		int curDir = dir;

		while (true)
		{
			if (cur == T)
			{
				break;
			}

			if (gears[cur][2] == gears[cur + 1][6])
			{
				break;
			}

			curDir *= -1;
			q.push({ ++cur, curDir });
		}

		cur = gear;
		curDir = dir;

		while (true)
		{
			if (cur == 1)
			{
				break;
			}

			if (gears[cur][6] == gears[cur - 1][2])
			{
				break;
			}

			curDir *= -1;
			q.push({ --cur, curDir });
		}

		while (!q.empty())
		{
			int idx = q.front().first;
			int d = q.front().second;
			q.pop();

			string cpy = gears[idx];

			for (int i = 0; i < 8; i++)
			{
				gears[idx][i] = cpy[((i + 8) + (d == 1 ? -1 : 1)) % 8];
			}
		}
	}

	int result = 0;

	for (int i = 1; i <= T; i++)
	{
		result += (gears[i][0] == '1');
	}

	cout << result << "\n";

	return 0;
}