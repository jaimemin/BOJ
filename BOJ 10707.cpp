#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C, D, P;
	cin >> A >> B >> C >> D >> P;

	int X = P * A;
	int Y = B + max(P - C, 0) * D;

	cout << min(X, Y) << "\n";

	return 0;
}