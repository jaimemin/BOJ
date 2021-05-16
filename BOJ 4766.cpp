#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double prevTemperature;
	cin >> prevTemperature;

	while (1)
	{
		double curTemperature;
		cin >> curTemperature;

		if (curTemperature == 999)
		{
			break;
		}

		printf("%.2lf\n", curTemperature - prevTemperature);

		prevTemperature = curTemperature;
	}

	return 0;
}