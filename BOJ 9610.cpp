#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int quadrants[4] = { 0, };
	int axis = 0;

	while (n--)
	{
		int x, y;
		cin >> x >> y;

		if (x == 0 || y == 0)
		{
			axis++;
		}
		else if (x > 0 && y > 0)
		{
			quadrants[0]++;
		}
		else if (x > 0 && y < 0)
		{
			quadrants[3]++;
		}
		else if (x < 0 && y > 0)
		{
			quadrants[1]++;
		}
		else
		{
			quadrants[2]++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cout << "Q" << i + 1 << ": " << quadrants[i] << "\n";
	}

	cout << "AXIS: " << axis << "\n";

	return 0;
}