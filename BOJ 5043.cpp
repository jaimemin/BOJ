#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long N;
	int b;
	cin >> N >> b;

	long long sum = 1;

	for (int i = 1; i <= b; i++)
	{
		sum += (1LL << i);
	}

	cout << (sum >= N ? "yes\n" : "no\n");

	return 0;
}