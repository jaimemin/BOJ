#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string grade;
	cin >> grade;

	if (grade == "F")
	{
		cout << "0.0\n";

		return 0;
	}

	double result = 0.0;

	switch (grade[0])
	{
	case 'A':
		result = 4.0;
		
		break;
	case 'B':
		result = 3.0;
		
		break;
	case 'C':
		result = 2.0;

		break;
	case 'D':
		result = 1.0;

		break;
	}

	switch (grade[1])
	{
	case '+':
		result += 0.3;

		break;
	case '-':
		result -= 0.3;

		break;
	}

	printf("%.1f\n", result);

	return 0;
}