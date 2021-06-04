#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t1, t2;
	cin >> t1 >> t2;

	int result = 2;

	while (t1 >= t2)
	{
		int temp = t1 - t2;
		t1 = t2;
		t2 = temp;

		result++;
	}

	cout << result << "\n";

	return 0;
}