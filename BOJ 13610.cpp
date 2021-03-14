#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int X, Y;
	cin >> X >> Y;

	int result;

	for (result = 1; (Y - X) * result < Y; result++) {}

	cout << result << "\n";

	return 0;
}