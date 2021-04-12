#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 300 + 1;
const int INF = 987654321;

int N, M;
int cache[MAX][MAX];

void initialize(void)
{
	memset(cache, -1, sizeof(cache));

	for (int i = 1; i < MAX; i++)
	{
		cache[i][1] = i - 1;
		cache[1][i] = i - 1;
	}
}

int getMinDivideCnt(int r, int c)
{
	int &result = cache[r][c];

	if (result != -1)
	{
		return result;
	}

	int temp = INF;

	for (int i = 1; i <= (r + 1) / 2; i++)
	{
		temp = min(temp, getMinDivideCnt(i, c) + getMinDivideCnt(r - i, c));
	}

	for (int i = 1; i <= (c + 1) / 2; i++)
	{
		temp = min(temp, getMinDivideCnt(r, i) + getMinDivideCnt(r, c - i));
	}

	result = temp + 1;

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	initialize();

	cout << getMinDivideCnt(N, M) << "\n";

	return 0;
}