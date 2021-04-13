#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long A, B;
	cin >> A >> B;

	if (A > B)
	{
		swap(A, B);
	}

	long long result = (A + B) * (B - A + 1) / 2;

	cout << result << "\n";

	return 0;
}