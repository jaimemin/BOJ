#include <iostream>
using namespace std;

const double GALLON2LITER = 3.785411784;
const double MILE2KM = 1.609344;
const double HUNDRED_KM = 100.00;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double milesPerGallon;
	cin >> milesPerGallon;

	double result = HUNDRED_KM / ((MILE2KM / GALLON2LITER) * milesPerGallon);

	printf("%.6lf\n", result);

	return 0;
}