#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double a;
	cin >> a;

	double result = 4 * sqrt(a);

	printf("%.7lf\n", result);

	return 0;
}