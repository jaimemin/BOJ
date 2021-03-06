#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long UR, TR, UO, TO;
	cin >> UR >> TR >> UO >> TO;

	long long result = 56 * UR + 24 * TR + 14 * UO + 6 * TO;

	cout << result << "\n";

	return 0;
}