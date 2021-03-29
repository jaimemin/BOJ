#include <iostream>
#include <algorithm>
using namespace std;

const int WORKING_DAY = 21;
const int FIRST_OPTION_FREE_MINUTE = 30;
const int SECOND_OPTION_FREE_MINUTE = 45;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, x, b, y, T;
	cin >> a >> x >> b >> y >> T;

	int firstOption = max(0, T - FIRST_OPTION_FREE_MINUTE) * x * WORKING_DAY + a;
	int secondOption = max(0, T - SECOND_OPTION_FREE_MINUTE) * y * WORKING_DAY + b;

	cout << firstOption << " " << secondOption << "\n";

	return 0;
}