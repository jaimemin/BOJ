#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265359;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double a;
	cin >> a;

	double perimeter = sqrt(a / PI) * 2 * PI;

	printf("%.7lf\n", perimeter);

	return 0;
}