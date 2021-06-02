#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

const int WATER_COVER_PER_HOUR = 50;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		double X, Y;
		cin >> X >> Y;

		if (X == 0 && Y == 0)
		{
			break;
		}

		int hour = (int) ceil((X * X + Y * Y) * M_PI / (WATER_COVER_PER_HOUR * 2));

		cout << "The property will be flooded in hour " << hour << ".\n";
	}

	return 0;
}