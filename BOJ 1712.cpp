#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	if (B >= C)
	{
		cout << -1 << "\n";

		return 0;
	}

	int result = A / (C - B) + 1;

	cout << result << "\n";

	return 0;
}