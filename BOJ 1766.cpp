#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int MAX = 32000 + 320;

int N, M;
int inDegree[MAX];
vector<int> graph[MAX];

void topologicalSort(void)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int n = 1; n <= N; n++)
	{
		if (inDegree[n])
		{
			continue;
		}

		pq.push(n);
	}

	while (!pq.empty())
	{
		int question = pq.top();
		pq.pop();

		cout << question << " ";

		for (int next : graph[question])
		{
			if (--inDegree[next] == 0)
			{
				pq.push(next);
			}
		}
	}

	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int m = 0; m < M; m++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		inDegree[b]++;
	}

	topologicalSort();

	return 0;
}