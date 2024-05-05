#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 1e2;

int N;

double A[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	double result = A[0];
	double temp = A[0];

	for (int i = 1; i < N; i++)
	{
		if (A[i] > temp * A[i])
		{
			temp = A[i];
		}
		else
		{
			temp *= A[i];
		}

		result = max(result, temp);
	}

	printf("%.3lf\n", result);

	return 0;
}