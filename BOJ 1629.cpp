#include <iostream>
using namespace std;

long long func(long long A, long long B, long long C)
{
	if (B == 1)
	{
		return A % C;
	}

	long long result = func(A, B / 2, C);
	result = ((result % C) * (result % C)) % C;

	if (B % 2)
	{
		result = ((result % C) * A) % C;
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long A, B, C;
	cin >> A >> B >> C;

	cout << func(A, B, C) << "\n";

	return 0;
}