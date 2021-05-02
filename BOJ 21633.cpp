#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double k;
	cin >> k;

	double result = 25 + k * 0.01;
	result = max(result, 100.00);
	result = min(result, 2000.00);

	printf("%.2lf\n", result);

	return 0;
}