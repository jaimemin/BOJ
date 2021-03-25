#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double A1, P1, R1, P2;
	cin >> A1 >> P1 >> R1 >> P2;

	double slicePizza = A1 / P1;
	double wholePizza = R1 * R1 * PI / P2;

	if (slicePizza > wholePizza) 
	{
		cout << "Slice of pizza\n";
	}
	else
	{
		cout << "Whole pizza\n";
	}

	return 0;
}