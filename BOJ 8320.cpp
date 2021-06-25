#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int result = 0;
	map<pair<int, int>, bool> visited;

	for (int row = 1; row <= n; row++)
	{
		for (int col = 1; col <= n; col++)
		{
			if (row * col > n)
			{
				continue;
			}

			if (visited.count({ row, col }))
			{
				continue;
			}

			visited[{row, col}] = true;
			visited[{col, row}] = true;
			result++;
		}
	}

	cout << result << "\n";

	return 0;
}