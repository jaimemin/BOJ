#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double L;
	cin >> L;

	double result = L * L * sqrt(3) / 4;

	printf("%.10lf\n", result);

	return 0;
}
