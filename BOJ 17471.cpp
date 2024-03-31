#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 10;

const int INF = 987654321;

int N;

int people[MAX];

vector<int> v[MAX];

bool isConnected(int bit)
{
	bool visited[MAX] = { false, };
	int root = -1;

	for (int i = 0; i < N; i++)
	{
		if (bit & (1 << i))
		{
			root = i;

			break;
		}
	}

	if (root == -1)
	{
		return false;
	}

	queue<int> q;
	q.push(root);
	visited[root] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : v[cur])
		{
			if (visited[next])
			{
				continue;
			}

			if (!(bit & (1 << next)))
			{
				continue;
			}

			visited[next] = true;
			q.push(next);
		}
	}

	for (int i = 0; i < N; i++)
	{
		if ((bit & (1 << i)) && !visited[i])
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> people[i];
	}

	for (int i = 0; i < N; i++)
	{
		int cnt;
		cin >> cnt;

		for (int k = 0; k < cnt; k++)
		{
			int adj;
			cin >> adj;

			v[i].push_back(adj - 1);
			v[adj - 1].push_back(i);
		}
	}

	int result = INF;

	for (int bit = 1; bit < (1 << N); bit++)
	{
		if (!isConnected(bit) || !isConnected(~bit))
		{
			continue;
		}

		int sum = 0;
		int sum2 = 0;

		for (int i = 0; i < N; i++)
		{
			if (bit & (1 << i))
			{
				sum += people[i];
			}
			else
			{
				sum2 += people[i];
			}
		}

		result = min(result, abs(sum2 - sum));
	}

	cout << (result == INF ? -1 : result) << "\n";

	return 0;
}