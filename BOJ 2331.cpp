#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6;

int A, P;
vector<int> D;
int visited[MAX];

int square(int digit)
{
	int result = 1;

	for (int p = 0; p < P; p++)
	{
		result *= digit;
	}

	return result;
}

int calc(int num)
{
	vector<int> digits;

	while (num)
	{
		digits.push_back(num % 10);
		num /= 10;
	}

	int result = 0;

	for (int digit : digits)
	{
		result += square(digit);
	}

	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> P;

	D.push_back(A);
	visited[A] = true;

	while (1)
	{
		int temp = calc(A);

		if (++visited[temp] == 2)
		{
			break;
		}

		D.push_back(temp);
		A = temp;
	}

	int result = 0;

	for (int d : D)
	{
		if (visited[d] == 2)
		{
			break;
		}

		result++;
	}

	cout << result << "\n";

	return 0;
}