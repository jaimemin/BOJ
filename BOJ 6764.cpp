#include <iostream>
using namespace std;

const int MAX = 4;

void printResult(bool allIdentical, bool isRising, bool isDiving)
{
	if (allIdentical)
	{
		cout << "Fish At Constant Depth\n";

		return;
	}

	if (isRising)
	{
		cout << "Fish Rising\n";

		return;
	}

	if (isDiving)
	{
		cout << "Fish Diving\n";

		return;
	}

	cout << "No Fish\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int depth[MAX];

	bool allIdentical = true;
	bool isRising = true;
	bool isDiving = true;

	for (int i = 0; i < MAX; i++)
	{
		cin >> depth[i];

		if (i && depth[i] != depth[i - 1])
		{
			allIdentical = false;
		}

		if (isRising && i && depth[i] <= depth[i - 1])
		{
			isRising = false;
		}

		if (isDiving && i && depth[i] >= depth[i - 1])
		{
			isDiving = false;
		}
	}

	printResult(allIdentical, isRising, isDiving);

	return 0;
}