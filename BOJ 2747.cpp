#include <iostream>
using namespace std;

const int MAX = 45 + 1;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	long long fibonacci[MAX];
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	cout << fibonacci[n] << "\n";

	return 0;
}
