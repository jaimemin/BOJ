#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int X;
	cin >> X;

	sort(v.begin(), v.end());

	int result = 0;
	int left = 0;
	int right = N - 1;

	while (left < right)
	{
		if (v[left] + v[right] > X)
		{
			right--;
		}
		else if (v[left] + v[right] < X)
		{
			left++;
		}
		else
		{
			result++;
			right--;
		}
	}

	cout << result << "\n";

	return 0;
}