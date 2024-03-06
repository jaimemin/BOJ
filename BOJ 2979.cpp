#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100 + 10;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	int cnt[MAX] = { 0, };
	int start = MAX;
	int end = 0;

	for (int i = 0; i < 3; i++)
	{
		int from, to;
		cin >> from >> to;

		start = min(start, from);
		end = max(end, to);

		for (int t = from; t < to; t++)
		{
			cnt[t]++;
		}
	}

	int answer = 0;

	for (int t = start; t < end; t++)
	{
		switch (cnt[t])
		{
		case 1:
			answer += A;

			break;
		case 2:
			answer += B * 2;

			break;
		case 3:
			answer += C * 3;

			break;
		}
	}

	cout << answer << "\n";

	return 0;
}