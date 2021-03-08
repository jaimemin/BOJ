#include <iostream>
#include <algorithm>
using namespace std;

bool isAllSame(int a, int b, int c)
{
	return a == b && b == c;
}

bool isAllDifferent(int a, int b, int c)
{
	return a != b && b != c && c != a;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;

	if (isAllSame(A, B, C))
	{
		cout << 10000 + 1000 * A << "\n";
	}
	else if (isAllDifferent(A, B, C))
	{
		cout << max(A, max(B, C)) * 100 << "\n";
	}
	else
	{
		if (A == B || A == C)
		{
			cout << 1000 + A * 100 << "\n";
		}
		else
		{
			cout << 1000 + B * 100 << "\n";
		}
	}

	return 0;
}