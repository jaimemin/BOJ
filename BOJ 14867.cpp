#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int a, b, c, d;

map<pair<int, int>, int> visited;

int func(void)
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visited[{0, 0}] = 0;

	while (!q.empty())
	{
		int A = q.front().first;
		int B = q.front().second;
		int cnt = visited[{A, B}];
		q.pop();

		if (A == c && B == d)
		{
			return cnt;
		}

		if (visited.count({a, B}) == 0)
		{
			q.push({a, B});

			visited[{a, B}] = cnt + 1;
		}

		if (visited.count({A, b}) == 0)
		{

			q.push({A, b});

			visited[{A, b}] = cnt + 1;
		}

		if (visited.count({0, B}) == 0)
		{
			q.push({0, B});

			visited[{0, B}] = cnt + 1;
		}

		if (visited.count({ A, 0 }) == 0)
		{
			q.push({ A, 0 });

			visited[{A, 0}] = cnt + 1;
		}

		int newA, newB;
		newB = A + B;

		if (A > b - B)
		{
			newA = A + B - b;
			newB = b;
		}
		else
		{
			newA = 0;
			newB = A + B;
		}

		if (visited.count({newA, newB}) == 0)
		{

			q.push({newA, newB});

			visited[{newA, newB}] = cnt + 1;
		}

		if (B > a - A)
		{
			newA = a;
			newB = B + A - a;
		}
		else
		{
			newA = A + B;
			newB = 0;
		}

		if (visited.count({newA, newB}) == 0)
		{
			q.push({newA, newB});

			visited[{newA, newB}] = cnt + 1;
		}
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	cin >> c >> d;

	cout << func() << "\n";

	return 0;
}