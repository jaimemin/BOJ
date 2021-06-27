#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 3;

typedef struct
{
	int calc, idx;
} State;

bool cmp(State a, State b)
{
	return a.calc < b.calc;
}

void printNumber(int a)
{
	if (a >= 0)
	{
		cout << a;
	}
	else
	{
		cout << "(" << a << ")";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;

	State result[MAX] = { {a + b, 0}, {a - b, 1}, {a*b, 2} };

	sort(result, result + MAX, cmp);

	if (result[2].calc == result[1].calc)
	{
		cout << "NIE\n";

		return 0;
	}

	printNumber(a);

	switch (result[2].idx)
	{
	case 0:
		cout << "+";

		break;
	case 1:
		cout << "-";

		break;
	case 2:
		cout << "*";

		break;
	}

	printNumber(b);

	cout << "=";
	printNumber(result[2].calc);
	cout << "\n";

	return 0;
}