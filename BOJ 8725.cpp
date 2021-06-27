#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int rowMax = -INF;

		for (int j = 0; j < n; j++)
		{
			int score;
			cin >> score;

			rowMax = max(rowMax, score);
		}

		result += max(0, rowMax);
	}

	cout << result << "\n";

	return 0;
}