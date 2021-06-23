#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double A, C, E;
	cin >> A >> C >> E;

	double studentA, studentC, studentE;
	cin >> studentA >> studentC >> studentE;

	if (studentA >= A && studentC >= C && studentE >= E)
	{
		cout << "A\n";

		return 0;
	}

	if (studentA >= A / 2 && studentC >= C && studentE >= E)
	{
		cout << "B\n";

		return 0;
	}

	if (studentC >= C && studentE >= E)
	{
		cout << "C\n";

		return 0;
	}

	if (studentC >= C / 2 && studentE >= E / 2)
	{
		cout << "D\n";

		return 0;
	}

	cout << "E\n";

	return 0;
}