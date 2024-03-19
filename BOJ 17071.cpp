#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 5e5 + 1;

typedef struct
{
	int location, second;
} State;

int N, K;

int getSum(int num)
{
	return num * (num + 1) / 2;
}

bool visited[MAX][2];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	queue<State> q;
	q.push({ N, 0 });
	visited[N][0] = 0;

	while (!q.empty())
	{
		int curLocation = q.front().location;
		int curSecond = q.front().second;
		q.pop();

		int target = K + getSum(curSecond);

		if (target >= MAX)
		{
			break;
		}

		if (visited[target][curSecond % 2])
		{
			cout << curSecond << "\n";
			
			return 0;
		}

		if (curLocation + 1 < MAX && !visited[curLocation + 1][(curSecond + 1) % 2])
		{
			visited[curLocation + 1][(curSecond + 1) % 2] = true;
			q.push({ curLocation + 1, curSecond + 1 });
		}

		if (curLocation - 1 >= 0 && !visited[curLocation - 1][(curSecond + 1) % 2])
		{
			visited[curLocation - 1][(curSecond + 1) % 2] = true;
			q.push({ curLocation - 1, curSecond + 1 });
		}

		if (curLocation * 2 < MAX && !visited[curLocation * 2][(curSecond + 1) % 2])
		{
			visited[curLocation * 2][(curSecond + 1) % 2] = true;
			q.push({ curLocation * 2, curSecond + 1 });
		}
	}

	cout << -1 << "\n";

	return 0;
}