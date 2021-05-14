#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double R;
	cin >> R;

	printf("%.6lf\n", R * R * M_PI);
	printf("%.6lf\n", R * R * 2);

	return 0;
}