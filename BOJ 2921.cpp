#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int upper = 0;

	for (int i = 1; i <= N; i++)
	{
		upper += i * (i + 1) / 2;
	}

	int lower = 0;

	for (int i = 1; i <= N; i++)
	{
		lower += i * (i + 1);
	}

	int result = lower + upper;

	cout << result << "\n";

	return 0;
}