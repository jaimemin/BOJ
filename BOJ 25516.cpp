#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100000;

int result;

int n, k;

int apples[MAX];

vector<int> graph[MAX];

void func(int node, int dist)
{
	if (dist > k)
	{
		return;
	}

	result += apples[node];

	for (int next : graph[node])
	{
		func(next, dist + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	for (int i = 0; i < n - 1; i++)
	{
		int p, c;
		cin >> p >> c;

		graph[p].push_back(c);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> apples[i];
	}

	func(0, 0);

	cout << result << "\n";

	return 0;
}