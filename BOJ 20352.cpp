#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926535897932384;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double a;
	cin >> a;

	double result = sqrt(a / PI) * 2 * PI;

	printf("%.7lf\n", result);
	
	return 0;
}