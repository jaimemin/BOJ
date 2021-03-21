#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double A, B, C;
	cin >> A >> B >> C;

	double result = max(A / B * C, A * B / C);

	cout << (int)result << "\n";

	return 0;
}