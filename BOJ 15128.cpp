#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long p1, q1, p2, q2;
	cin >> p1 >> q1 >> p2 >> q2;

	bool isAreaInteger = (p1 * p2 % (q1 * q2 * 2) == 0);

	cout << isAreaInteger << "\n";

	return 0;
}