#include <iostream>
#include <algorithm>
using namespace std;

long long GCD(long long a, long long b)
{
	if (a % b == 0)
	{
		return b;
	}

	return GCD(b, a % b);
}

long long LCM(long long a, long long b)
{
	return a * b / GCD(a, b);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b;
	cin >> a >> b;

	cout << GCD(max(a, b), min(a, b)) << "\n" << LCM(max(a, b), min(a, b)) << "\n";

	return 0;
}