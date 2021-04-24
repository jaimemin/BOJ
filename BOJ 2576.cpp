#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 7;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> odds;

	int sum = 0;

	for (int i = 0; i < MAX; i++)
	{
		int num;
		cin >> num;

		if (num % 2)
		{
			odds.push_back(num);

			sum += num;
		}
	}

	if (odds.empty())
	{
		cout << -1 << "\n";

		return 0;
	}

	sort(odds.begin(), odds.end());

	cout << sum << "\n" << odds[0] << "\n";

	return 0;
}