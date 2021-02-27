#include <iostream>
using namespace std;

const int MAX = 9;

void printResult(int A, int B)
{
	cout << A / B << ".";

	int mod = A % B;

	for (int i = 0; i < MAX; i++)
	{
		mod *= 10;
		cout << mod / B;

		mod %= B;
	}

	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B;
	cin >> A >> B;

	printResult(A, B);

	return 0;
}