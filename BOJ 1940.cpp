#include <iostream>
#include <set>
using namespace std;

const int MAX = 1e6 + 100;

bool visited[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;

	set<int> s;

	for (int i = 0; i < N; i++)
	{
		int idx;
		cin >> idx;

		s.insert(idx);
	}

	int result = 0;

	for (int num : s)
	{
		if (visited[num])
		{
			continue;
		}

		if (num == M - num)
		{
			continue;
		}

		if (s.find(M - num) != s.end())
		{
			result++;
			visited[num] = true;
			visited[M - num] = true;
		}
	}

	cout << result << "\n";

	return 0;
}