#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A1, A2, A3;
	cin >> A1 >> A2 >> A3;

	int result = min(A2 * 2 + A3 * 4, min(A1 * 2 + A3 * 2, A1 * 4 + A2 * 2));

	cout << result << "\n";

	return 0;
}