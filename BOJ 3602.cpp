#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int b, w;
	cin >> b >> w;

	bool canMakeSquare = false;
	int maxSide;

	for (int side = 1; ; side++)
	{
		int half = (side * side) / 2;
		int otherHalf = (side * side) - half;

		if ((b >= half && w >= otherHalf) 
			|| (w >= half && b >= otherHalf))
		{
			canMakeSquare = true;

			maxSide = side;
		}
		else
		{
			break;
		}
	}

	if (canMakeSquare == false)
	{
		cout << "Impossible\n";
	}
	else
	{
		cout << maxSide << "\n";
	}

	return 0;
}