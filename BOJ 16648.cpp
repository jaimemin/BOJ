#include <iostream>
using namespace std;

const int MAX_BATTERY = 100;
const int ECO_MODE = 20;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double t, p;
	cin >> t >> p;

	double result;

	if (p >= ECO_MODE)
	{
		double drainPerDistance = (MAX_BATTERY - p) / t;

		result = ((p - ECO_MODE) / drainPerDistance) + (ECO_MODE / (drainPerDistance / 2));
	}
	else
	{
		double drainPerDistance = ((MAX_BATTERY - ECO_MODE) + (ECO_MODE - p) * 2) / t;

		result = p / (drainPerDistance / 2);
	}

	printf("%.5lf\n", result);

	return 0;
}