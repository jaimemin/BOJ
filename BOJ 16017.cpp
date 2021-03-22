#include <iostream>
using namespace std;

const int MAX = 4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bool isTelemarketNum = true;
	int number[MAX];

	for (int i = 0; i < MAX; i++)
	{
		cin >> number[i];

		if ((i == 0 || i == 3) && !(8 <= number[i] && 9 >= number[i]))
		{
			isTelemarketNum = false;
		}
		
		if (i == 2 && number[i] != number[i-1])
		{
			isTelemarketNum = false;
		}
	}

	cout << (isTelemarketNum ? "ignore\n" : "answer\n");

	return 0;
}