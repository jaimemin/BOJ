#include <iostream>
#include <queue>
using namespace std;

const int MAX = 2000 + 20;

queue<int> q[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		int cnt;
		cin >> cnt;

		for (int c = 0; c < cnt; c++)
		{
			int box;
			cin >> box;

			q[i].push(box);
		}
	}

	int extra = 0;

	for (int i = 1; i <= N && extra <= K; i++)
	{
		while (true)
		{
			if (q[i].size() <= M)
			{
				break;
			}

			if (++extra > K)
			{
				cout << 0 << "\n";

				return 0;
			}

			for (int k = 0; k < M; k++)
			{
				q[N + extra].push(q[i].front());

				q[i].pop();
			}

			q[i].push(N + extra);
		}
	}

	cout << 1 << "\n" << extra << "\n";

	for (int i = 1; i <= N + extra; i++)
	{
		cout << q[i].size();

		while (!q[i].empty())
		{
			cout << " " << q[i].front();
			
			q[i].pop();
		}

		cout << "\n";
	}

	return 0;
}