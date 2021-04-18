#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	int result = 0;

	for (int i = 0; i < MAX; i++)
	{
		int descend, ascend;
		cin >> descend >> ascend;

		sum += (ascend - descend);
		result = max(result, sum);
	}

	cout << result << "\n";

	return 0;
}