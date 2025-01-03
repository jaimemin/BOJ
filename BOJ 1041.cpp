#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long getSum3(vector<long long> v)
{
	int temp[4] = { 0, 1, 5, 4 };
	int temp2[4] = { 1, 5, 4, 0 };
	long long result = v[0] + v[1] + v[2];

	for (int i = 0; i < 4; i++)
	{
		result = min(result, v[temp[i]] + v[temp2[i]] + (v[temp[i]] + v[temp2[i]] + v[3] > v[temp[i]] + v[temp2[i]] + v[2] ? v[2] : v[3]));
	}

	return result;
}

long long getSum2(vector<long long> v)
{
	long long result = v[0] + v[1];

	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if ((i == 0 && j == 5) 
				|| (i == 1 && j == 4) 
				|| (i == 2 && j == 3))
			{
				continue;
			}

			result = min(result, v[i] + v[j]);
		}
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long N;
	cin >> N;

	vector<long long> v(6);

	for (int i = 0; i < 6; i++)
	{
		cin >> v[i];
	}

	long long sum3 = getSum3(v);
	long long sum2 = getSum2(v);

	sort(v.begin(), v.end());

	long long result = 0;

	// 1일 때는 예외
	if (N == 1)
	{
		for (int i = 0; i < 5; i++)
		{
			result += v[i];
		}

		cout << result << "\n";

		return 0;
	}

	// 3면 * 4
	result += sum3 * 4;
	// 2면 * (2N - 3) * 4)
	result += sum2 * (N - 1) * 4;
	result += sum2 * (N - 2) * 4;
	// 1면 * ((N - 2) ^ 2 + ((N - 2) * (N - 1) * 4))
	result += v[0] * (N - 2) * (N - 2);
	result += v[0] * (N - 2) * (N - 1) * 4;

	cout << result << "\n";

	return 0;
}