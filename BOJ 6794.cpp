#include <iostream>
using namespace std;

const int MAX = 5;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	bool visited[MAX + 1][MAX + 1] = { false, };

	int result = 0;

	for (int i = 0; i <= MAX; i++)
	{
		for (int j = 0; j <= MAX; j++)
		{
			if (visited[i][j])
			{
				continue;
			}

			if (i + j == n)
			{
				visited[i][j] = true;
				visited[j][i] = true;

				result++;
			}
		}
	}

	cout << result << "\n";

	return 0;
}