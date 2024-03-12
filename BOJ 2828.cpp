#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int result = INF;
int N, M, J;

vector<int> apples;

void func(int idx, int left, int right, int total)
{
	if (idx == apples.size())
	{
		result = min(result, total);

		return;
	}

	int cnt = 0;
	bool possible = true;
	int copyLeft = left;
	int copyRight = right;

	while (!(left <= apples[idx] && apples[idx] <= right))
	{
		left = left + 1;
		right = right + 1;
		cnt++;

		if (right > N)
		{
			possible = false;

			break;
		}
	}

	if (possible)
	{
		func(idx + 1, left, right, total + cnt);
	}

	cnt = 0;
	possible = true;
	left = copyLeft;
	right = copyRight;

	while (!(left <= apples[idx] && apples[idx] <= right))
	{
		left = left - 1;
		right = right - 1;
		cnt++;

		if (left < 1)
		{
			possible = false;

			break;
		}
	}

	if (possible)
	{
		func(idx + 1, left, right, total + cnt);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> J;

	int left = 1, right = M;
	int result = 0;

	for (int j = 0; j < J; j++)
	{
		int apple;
		cin >> apple;

		right = left + M - 1;

		if (apple >= left && apple <= right)
		{
			continue;
		}

		if (apple < left)
		{
			result += (left - apple);
			left = apple;
		}
		else
		{
			left += (apple - right);
			result += (apple - right);
		}
	}

	cout << result << "\n";

	return 0;
}