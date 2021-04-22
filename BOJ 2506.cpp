#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int result = 0;
	int consecutiveCnt = 1;

	for (int i = 0; i < N; i++)
	{
		bool isCorrect;
		cin >> isCorrect;

		if (isCorrect)
		{
			result += consecutiveCnt++;
		}
		else
		{
			consecutiveCnt = 1;
		}
	}

	cout << result << "\n";

	return 0;
}