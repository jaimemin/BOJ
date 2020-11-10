#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 500 + 50;

int N;
int inDegree[MAX];
int delay[MAX];
int cache[MAX];
vector<int> graph[MAX];

void getMinimumTime(void)
{
	int result = 0;
	queue<int> q;

	for (int n = 1; n <= N; n++)
	{
		if (inDegree[n])
		{
			continue;
		}

		q.push(n);
		cache[n] = delay[n];
	}

	while (!q.empty())
	{
		int building = q.front();
		q.pop();

		for (int next : graph[building])
		{
			if (--inDegree[next] == 0)
			{
				q.push(next);
			}

			cache[next] = max(cache[next], cache[building] + delay[next]);
		}
	}

	for (int n = 1; n <= N; n++)
	{
		cout << cache[n] << "\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int n = 1; n <= N; n++)
	{
		cin >> delay[n];

		while (1)
		{
			int building;
			cin >> building;

			if (building == -1)
			{
				break;
			}

			graph[building].push_back(n);
			inDegree[n]++;
		}
	}

	getMinimumTime();

	return 0;
}