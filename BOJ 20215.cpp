#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double w, h;
	cin >> w >> h;

	double result = (w + h) - sqrt(w * w + h * h);

	printf("%.6lf\n", result);

	return 0;
}