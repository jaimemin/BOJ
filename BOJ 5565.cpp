#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int totalSum = 0;
	cin >> totalSum;

	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		int cost;
		cin >> cost;

		sum += cost;
	}

	cout << totalSum - sum << "\n";

	return 0;
}