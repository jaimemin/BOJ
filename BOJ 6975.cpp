#include <iostream>
using namespace std;

void getResult(int num)
{
	int sum = 0;

	for (int i = 1; i < num; i++)
	{
		if (num%i == 0)
		{
			sum += i;
		}
	}

	cout << num;

	if (sum < num)
	{
		cout << " is a deficient number.\n";
	}
	else if (sum == num)
	{
		cout << " is a perfect number.\n";
	}
	else
	{
		cout << " is an abundant number.\n";
	}

	cout << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		int num;
		cin >> num;

		getResult(num);
	}

	return 0;
}