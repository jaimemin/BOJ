#include <iostream>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

const int MAX = 1e3 + 1e2;

int N, M, V;

set<int> graph[MAX];

bool visited[MAX];

void dfs(int node)
{
	cout << node << " ";
	visited[node] = true;

	for (int next : graph[node])
	{
		if (visited[next])
		{
			continue;
		}

		dfs(next);
	}
}

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int next : graph[cur])
		{
			if (visited[next])
			{
				continue;
			}

			visited[next] = true;
			q.push(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].insert(b);
		graph[b].insert(a);
	}

	dfs(V);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	bfs(V);
	cout << "\n";

	return 0;
}