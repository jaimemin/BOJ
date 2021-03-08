#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int one, two;
	cin >> one >> two;

	int three = one * (two % 10);
	int four = one * ((two % 100) / 10);
	int five = one * ((two % 1000) / 100);
	int six = one * two;

	cout << three << "\n";
	cout << four << "\n";
	cout << five << "\n";
	cout << six << "\n";

	return 0;
}