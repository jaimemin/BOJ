#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 3;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int sides[MAX] = { 0, };

		for (int j = 0; j < MAX; j++)
		{
			cin >> sides[j];
		}

		sort(sides, sides + MAX);

		cout << "Scenario #" << i << ":\n";

		if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2])
		{
			cout << "yes\n\n";
		}
		else
		{
			cout << "no\n\n";
		}
	}

	return 0;
}