#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1010;

int N, M, V;
vector<int> vertexes[MAX];
bool visited[MAX];

void DFS(int node)
{
	cout << node << " ";

	for (int vertex : vertexes[node])
	{
		if (visited[vertex])
		{
			continue;
		}

		visited[vertex] = true;
		DFS(vertex);
	}
}

void BFS(int node)
{
	memset(visited, false, sizeof(visited));

	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();

		cout << curNode << " ";

		for (int vertex : vertexes[curNode])
		{
			if (visited[vertex])
			{
				continue;
			}

			visited[vertex] = true;
			q.push(vertex);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> V;

	for (int m = 0; m < M; m++)
	{
		int u, v;
		cin >> u >> v;

		vertexes[u].push_back(v);
		vertexes[v].push_back(u);
	}

	for (int n = 1; n <= N; n++)
	{
		sort(vertexes[n].begin(), vertexes[n].end());
	}

	visited[V] = true;
	DFS(V);
	cout << "\n";

	BFS(V);
	cout << "\n";

	return 0;
}