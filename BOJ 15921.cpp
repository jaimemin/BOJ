#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	if (N == 0)
	{
		cout << "divide by zero\n";

		return 0;
	}

	double sum = 0;
	double expectedValue = 0;

	for (int i = 0; i < N; i++)
	{
		double record;
		cin >> record;

		sum += record;
		expectedValue += record / N;
	}

	if ((int)expectedValue == 0)
	{
		cout << "divide by zero\n";

		return 0;
	}

	double average = sum / N;
	double result = average / expectedValue;

	printf("%.2lf\n", result);

	return 0;
}