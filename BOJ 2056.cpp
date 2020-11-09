#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10000 + 100;

int N;
int delay[MAX];
int inDegree[MAX];
int cache[MAX];
vector<int> graph[MAX];

int getMinimumTime(void)
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
		int job = q.front();
		q.pop();

		for (int next : graph[job])
		{
			if (--inDegree[next] == 0)
			{
				q.push(next);
			}

			cache[next] = max(cache[next], cache[job] + delay[next]);
		}
	}

	for (int n = 1; n <= N; n++)
	{
		result = max(result, cache[n]);
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int n = 1; n <= N; n++)
	{
		int time, num;
		cin >> time >> num;

		delay[n] = time;

		for (int i = 0; i < num; i++)
		{
			int job;
			cin >> job;

			graph[job].push_back(n);
			inDegree[n]++;
		}
	}

	cout << getMinimumTime() << "\n";

	return 0;
}