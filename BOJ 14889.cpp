#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 20;

int N;

int S[MAX][MAX];

int result = 0x3f;

void func(int bit)
{
	vector<int> zeros, ones;

	for (int i = 0; i < N; i++)
	{
		if ((1 << i) & bit)
		{
			ones.push_back(i);
		}
		else
		{
			zeros.push_back(i);
		}
	}

	if (ones.size() != zeros.size())
	{
		return;
	}

	int zeroSum = 0, oneSum = 0;

	for (int i = 0; i < ones.size(); i++)
	{
		for (int j = i + 1; j < ones.size(); j++)
		{
			zeroSum += S[zeros[i]][zeros[j]] + S[zeros[j]][zeros[i]];
			oneSum += S[ones[i]][ones[j]] + S[ones[j]][ones[i]];
		}
	}

	result = min(result, abs(zeroSum - oneSum));
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> S[i][j];
		}
	}

	for (int i = 1; i < (1 << N); i++)
	{
		func(i);
	}

	cout << result << "\n";

	return 0;
}