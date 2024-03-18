#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const int MAX = 1e5 + 1;

int result;

int minSecond;

bool visited[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty())
	{
		int curLocation = q.front().first;
		int curSecond = q.front().second;
		q.pop();

		visited[curLocation] = true;

		if (minSecond 
			&& minSecond == curSecond 
			&& curLocation == K)
		{
			result++;
		}

		if (!minSecond && curLocation == K)
		{
			minSecond = curSecond;
			result++;
		}

		if (curLocation + 1 < MAX && !visited[curLocation + 1])
		{
			q.push({ curLocation + 1, curSecond + 1 });
		}
		
		if (curLocation - 1 >= 0 && !visited[curLocation - 1])
		{
			q.push({ curLocation - 1, curSecond + 1 });
		}

		if (curLocation * 2 < MAX && !visited[curLocation * 2])
		{
			q.push({ curLocation * 2, curSecond + 1 });
		}
	}

	cout << minSecond << "\n";
	cout << result << "\n";

	return 0;
}