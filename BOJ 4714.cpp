#include <iostream>
using namespace std;

const double MOON_WEIGHT_RATIO = 0.167;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		double weight;
		cin >> weight;

		if (weight < 0.00)
		{
			break;
		}

		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", weight, weight * MOON_WEIGHT_RATIO);
	}

	return 0;
}