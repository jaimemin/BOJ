#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, i;
	cin >> A >> B >> i;

	int result = (A / i) * (B / i) - max(0, A / i - 2) * max(0, B / i - 2);

	cout << result << "\n";

	return 0;
}