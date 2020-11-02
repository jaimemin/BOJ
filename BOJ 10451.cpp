#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000 + 10;

int T, N;
int permutations[MAX];
bool visited[MAX];

void init(void)
{
	memset(permutations, 0, sizeof(permutations));
	memset(visited, false, sizeof(visited));
}

void DFS(int node)
{
	if (visited[node])
	{
		return;
	}

	visited[node] = true;
	DFS(permutations[node]);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		init();

		for (int n = 1; n <= N; n++)
		{
			cin >> permutations[n];
		}

		int result = 0;

		for (int n = 1; n <= N; n++)
		{
			if (visited[n])
			{
				continue;
			}

			DFS(n);
			result++;
		}

		cout << result << "\n";
	}

	return 0;
}