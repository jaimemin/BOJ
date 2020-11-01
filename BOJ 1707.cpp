#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1e5 * 2 + 200;

int V, E, K;
vector<int> vertexes[MAX];
int colors[MAX];

void init(void)
{
	for (int v = 1; v <= V; v++)
	{
		vertexes[v].clear();
	}

	memset(colors, 0, sizeof(colors));
}

void DFS(int node, int color)
{
	colors[node] = color;

	for (int vertex : vertexes[node])
	{
		if (colors[vertex])
		{
			continue;
		}

		DFS(vertex, 3 - color);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> K;

	for (int k = 0; k < K; k++)
	{
		init();

		cin >> V >> E;

		for (int e = 0; e < E; e++)
		{
			int u, v;
			cin >> u >> v;

			vertexes[u].push_back(v);
			vertexes[v].push_back(u);
		}

		for (int v = 1; v <= V; v++)
		{
			if (colors[v])
			{
				continue;
			}

			DFS(v, 1);
		}

		bool result = true;

		for (int v = 1; v <= V; v++)
		{
			for (int vertex : vertexes[v])
			{
				if (colors[v] == colors[vertex])
				{
					result = false;

					break;
				}
			}

			if (result == false)
			{
				break;
			}
		}

		if (result)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}