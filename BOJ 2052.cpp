#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	double result = pow(0.5, N);

	printf("%.*f\n", N, result);

	return 0;
}
