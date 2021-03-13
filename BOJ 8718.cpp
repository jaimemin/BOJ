#include <iostream>
using namespace std;

void printSnowmanSize(int x, int k)
{
	x *= 1000;

	// k�� ���� ���� ���
	int kSmallest = 7000 * k;

	if (kSmallest <= x)
	{
		cout << kSmallest << "\n";

		return;
	}

	// k�� ���
	int kMiddle = 3500 * k;

	if (kMiddle <= x)
	{
		cout << kMiddle << "\n";

		return;
	}

	// k�� ���� ū ���
	int kBiggest = 1750 * k;

	if (kBiggest <= x)
	{
		cout << kBiggest << "\n";

		return;
	}

	// ���� ���� ����
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