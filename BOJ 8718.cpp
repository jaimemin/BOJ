#include <iostream>
using namespace std;

void printSnowmanSize(int x, int k)
{
	x *= 1000;

	// k가 제일 작은 경우
	int kSmallest = 7000 * k;

	if (kSmallest <= x)
	{
		cout << kSmallest << "\n";

		return;
	}

	// k가 가운데
	int kMiddle = 3500 * k;

	if (kMiddle <= x)
	{
		cout << kMiddle << "\n";

		return;
	}

	// k가 제일 큰 경우
	int kBiggest = 1750 * k;

	if (kBiggest <= x)
	{
		cout << kBiggest << "\n";

		return;
	}

	// 조건 만족 못함
	cout << 0 << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x, k;
	cin >> x >> k;

	printSnowmanSize(x, k);
	
	return 0;
}