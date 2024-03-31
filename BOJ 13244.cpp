#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000 + 1;

vector<int> graph[MAX];

bool visited[MAX];

void func(int node)
{
	visited[node] = true;

	for (int next : graph[node])
	{
		if (!visited[next])
		{
			func(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int N, M;
		cin >> N >> M;

		for (int i = 0; i < M; i++)
		{
			int A, B;
			cin >> A >> B;

			graph[A].push_back(B);
			graph[B].push_back(A);
		}

		int cnt = 0;
		memset(visited, false, sizeof(visited));

		for (int node = 1; node <= N; node++)
		{
			if (!visited[node])
			{
				func(node);
				cnt++;
			}
		}

		cout << (N == M + 1 && cnt == 1 ? "tree" : "graph") << "\n";

		for (int node = 1; node < MAX; node++)
		{
			graph[node].clear();
		}
	}

	return 0;
}