#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;

	long long result = a >= b ? b : a + 1;

	cout << result << "\n";

	return 0;
}