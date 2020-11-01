#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000 + 10;

int N, M;
vector<int> vertexes[MAX];
bool visited[MAX];

void DFS(int node)
{
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

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int m = 0; m < M; m++)
	{
		int u, v;
		cin >> u >> v;

		vertexes[u].push_back(v);
		vertexes[v].push_back(u);
	}

	int result = 0;

	for (int n = 1; n <= N; n++)
	{
		if (visited[n])
		{
			continue;
		}

		visited[n] = true;
		result++;
		DFS(n);
	}

	cout << result << "\n";

	return 0;
}