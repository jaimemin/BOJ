#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;

int result;

int minSecond;

bool visited[MAX];

int parent[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	for (int i = 0; i < MAX; i++)
	{
		parent[i] = i;
	}

	while (!q.empty())
	{
		int curLocation = q.front().first;
		int curSecond = q.front().second;
		q.pop();

		if (!minSecond && curLocation == K)
		{
			minSecond = curSecond;

			break;
		}

		if (curLocation + 1 < MAX && !visited[curLocation + 1])
		{
			visited[curLocation + 1] = true;
			parent[curLocation + 1] = curLocation;
			q.push({ curLocation + 1, curSecond + 1 });
		}

		if (curLocation - 1 >= 0 && !visited[curLocation - 1])
		{
			visited[curLocation - 1] = true;
			parent[curLocation - 1] = curLocation;
			q.push({ curLocation - 1, curSecond + 1 });
		}

		if (curLocation * 2 < MAX && !visited[curLocation * 2])
		{
			visited[curLocation * 2] = true;
			parent[curLocation * 2] = curLocation;
			q.push({ curLocation * 2, curSecond + 1 });
		}
	}

	cout << minSecond << "\n";
	
	vector<int> v;

	int idx = K;

	while (idx != N)
	{
		v.push_back(idx);

		idx = parent[idx];
	}

	v.push_back(N);

	for (int i = v.size() - 1; i >= 0; i--)
	{
		cout << v[i];

		if (i != 0)
		{
			cout << " ";
		}
	}
	
	cout << "\n";

	return 0;
}