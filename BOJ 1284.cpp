#include <iostream>
using namespace std;

int getWidth(int N)
{
	int result = 2; // 양 옆

	while (N)
	{
		int temp = N % 10;

		switch (temp)
		{
		case 1:
			result += 2;

			break;
		case 0:
			result += 4;

			break;
		default:
			result += 3;
		}

		N /= 10;

		// 다음 숫자 있을 때 한칸 띄어야하므로
		if (N)
		{
			result++;
		}
	}

	return result;
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		int N;
		cin >> N;

		if (N == 0)
		{
			break;
		}

		cout << getWidth(N) << "\n";
	}

	return 0;
}