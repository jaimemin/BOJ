#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	while (1)
	{
		double d, rh, rv;
		cin >> d >> rh >> rv;

		if (d == 0 && rh == 0 && rv == 0)
		{
			break;
		}

		double W = 16 * d / sqrt(337);
		double H = 9 * W / 16;
		double horizontalDPI = rh / W;
		double verticalDPI = rv / H;

		printf("Horizontal DPI: %.2lf\nVertical DPI: %.2lf\n", horizontalDPI, verticalDPI);
	}

	return 0;
}