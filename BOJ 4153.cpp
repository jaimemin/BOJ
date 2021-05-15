#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		vector<int> sides(3);
		cin >> sides[0] >> sides[1] >> sides[2];

		if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0)
		{
			break;
		}

		sort(sides.begin(), sides.end());

		if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2])
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}

	return 0;
}