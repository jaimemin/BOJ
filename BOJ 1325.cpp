#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int MAX = 10000 + 1;

int N, M;

vector<int> v[MAX];

bool visited[MAX];

int dfs(int node)
{
	visited[node] = true;
	int result = 0;
	int cnt = 0;

	for (int next : v[node])
	{
		if (visited[next])
		{
			continue;
		}

		cnt++;
		result += dfs(next);
	}

	return result + cnt;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	int maxHacking = 0;

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		v[B].push_back(A);
	}

	vector<int> computers;

	for (int i = 1; i <= N; i++)
	{
		memset(visited, false, sizeof(visited));
		int cnt = dfs(i);

		if (cnt > maxHacking)
		{
			computers.clear();
			computers.push_back(i);
			maxHacking = cnt;
		}
		else if (cnt == maxHacking)
		{
			computers.push_back(i);
		}
	}

	for (int i = 0; i < computers.size(); i++)
	{
		cout << computers[i];

		if (i != computers.size() - 1)
		{
			cout << " ";
		}
	}

	cout << "\n";

	return 0;
}