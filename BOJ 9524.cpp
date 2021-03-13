#include <iostream>
using namespace std;

const int MAX = 4;

int yekaterinburg[MAX] = { 1, 7, 2, 3 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int D;
	cin >> D;

	cout << yekaterinburg[D - 1] << "\n";

	return 0;
}