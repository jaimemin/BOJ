#include <iostream>
using namespace std;

const int MAX = 5;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int L;
	cin >> L;

	int result = L / MAX;

	if (L % MAX)
	{
		result++;
	}

	cout << result << "\n";

	return 0;
}