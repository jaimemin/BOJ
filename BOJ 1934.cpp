#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return GCD(b, a % b);
}

long long LCM(long long a, long long b)
{
	return (a * b) / GCD(a, b);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--)
	{
		int A, B;
		cin >> A >> B;

		cout << LCM(A, B) << "\n";
	}

	return 0;
}