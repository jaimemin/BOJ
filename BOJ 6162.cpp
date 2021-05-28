#include <iostream>
using namespace std;

void printResult(int k, int E, int A)
{
	cout << "Data Set " << k << ":\n";

	int cnt = 0;

	while (E > A)
	{
		A *= 5;

		cnt++;
	}

	if (cnt == 0)
	{
		cout << "no drought\n\n";

		return;
	}

	for (int i = 0; i < cnt - 1; i++)
	{
		cout << "mega ";
	}

	cout << "drought\n\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int K;
	cin >> K;

	for (int k = 1; k <= K; k++)
	{
		int E, A;
		cin >> E >> A;

		printResult(k, E, A);
	}

	return 0;
}