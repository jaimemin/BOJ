#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	vector<int> cnts(N);
	queue<int> q;

	for (int i = 0; i < N; i++)
	{
		cin >> cnts[i];

		q.push(i);
	}

	vector<int> answer(N, 0);
	int t = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		t++;

		if (--cnts[cur] == 0)
		{
			answer[cur] = t;
		}
		else
		{
			q.push(cur);
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << " ";
	}

	cout << "\n";

	return 0;
}