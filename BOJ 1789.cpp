#include <iostream>
using namespace std;

long long getSum(long long  n)
{
	return n * (n + 1) / 2;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long S;
	cin >> S;

	long long cnt = 1;
	long long sum = getSum(cnt);

	while (sum <= S)
	{
		sum = getSum(++cnt);
	}

	cout << cnt - 1 << "\n";

	return 0;
}