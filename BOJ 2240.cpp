#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1e3 + 1;

int T, W;

int A[MAX];

int cache[3][MAX][30 + 3];

int func(int tree, int time, int move)
{
	if (time == T)
	{
		return 0;
	}

	int& result = cache[tree][time][move];

	if (result != -1)
	{
		return result;
	}

	if (A[time] == tree)
	{
		if (move < W)
		{
			result = max(func(tree, time + 1, move) + 1, func(3 - tree, time + 1, move + 1));
		}
		else
		{
			result = func(tree, time + 1, move) + 1;
		}
	}
	else
	{
		if (move < W)
		{
			result = max(func(tree, time + 1, move), func(3 - tree, time + 1, move + 1) + 1);
		}
		else
		{
			result = func(tree, time + 1, move);
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T >> W;

	for (int i = 0; i < T; i++)
	{
		cin >> A[i];
	}

	memset(cache, -1, sizeof(cache));

	cout << func(1, 0, 0) << "\n";

	return 0;
}