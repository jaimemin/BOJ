#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

bool isDividable(vector<int> &v, int div)
{
	for (int num : v)
	{
		if (num % div)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<int> v(n);
	int minNum = INF;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];

		minNum = min(minNum, v[i]);
	}

	for (int i = 1; i <= minNum; i++)
	{
		if (isDividable(v, i))
		{
			cout << i << "\n";
		}
	}

	return 0;
}