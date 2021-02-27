#include <iostream>
using namespace std;

void printResult(int caseNum, int A, int B)
{
	cout << "Case #" << caseNum << ": " << A + B << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int A, B;
		cin >> A >> B;

		printResult(t, A, B);
	}

	return 0;
}