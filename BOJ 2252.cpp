#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 32000 + 320;

int N, M;
int inDegree[MAX];
vector<int> graph[MAX];

void topological_sort(void)
{
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i])
		{
			continue;
		}

		q.push(i);
	}

	while (!q.empty())
	{
		int student = q.front();
		q.pop();

		cout << student << " ";

		for (int next : graph[student])
		{
			if (--inDegree[next] == 0)
			{
				q.push(next);
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

	topological_sort();

	return 0;
}
