#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sum, subtract;
	cin >> sum >> subtract;

	if (sum < subtract)
	{
		cout << -1 << "\n";

		return 0;
	}

	int A = (sum + subtract) / 2;
	int B = sum - A;

	if (abs(A - B) != subtract)
	{
		cout << -1 << "\n";

		return 0;
	}

	if (A > B)
	{
		cout << A << " " << B << "\n";
	}
	else
	{
		cout << B << " " << A << "\n";
	}

	return 0;
}