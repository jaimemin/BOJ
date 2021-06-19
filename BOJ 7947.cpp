#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10;

int main(void)
{
	int Z;
	cin >> Z;

	for (int z = 0; z < Z; z++)
	{
		double red = 0, green = 0, blue = 0;

		for (int i = 0; i < MAX; i++)
		{
			double r, g, b;
			cin >> r >> g >> b;

			red += r;
			green += g;
			blue += b;
		}

		printf("%.lf %.lf %.lf\n", round(red / MAX), round(green / MAX), round(blue / MAX));
	}

	return 0;
}