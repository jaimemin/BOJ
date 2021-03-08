#include <iostream>
using namespace std;

bool isYearYoonNyeon(int year)
{
	return (year % 4 == 0 && year % 100) || (year % 400 == 0);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int year;
	cin >> year;

	cout << isYearYoonNyeon(year) << "\n";

	return 0;
}