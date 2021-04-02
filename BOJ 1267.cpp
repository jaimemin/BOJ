#include <iostream>
using namespace std;

const int YOUNGSIK = 30;
const int YOUNGSIK_PRICE = 10;
const int MINSIK = 60;
const int MINSIK_PRICE = 15;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int YSum = 0, MSum = 0;

	for (int i = 0; i < N; i++)
	{
		int second;
		cin >> second;

		YSum += (second / YOUNGSIK + ((second + 1) % YOUNGSIK != 0)) * YOUNGSIK_PRICE;
		MSum += (second / MINSIK + ((second + 1) % MINSIK != 0)) * MINSIK_PRICE;
	}

	if (YSum == MSum)
	{
		cout << "Y M " << YSum << "\n";
	}
	else if (YSum > MSum)
	{
		cout << "M " << MSum << "\n";
	}
	else
	{
		cout << "Y " << YSum << "\n";
	}

	return 0;
}