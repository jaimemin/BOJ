#include <iostream>
using namespace std;

const int MAX = 6;
const int PRICE = 5;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int sum = 0;

	for (int i = 0; i < MAX; i++)
	{
		int num;
		cin >> num;

		sum += num;
	}

	cout << sum * PRICE << "\n";
	
	return 0;
}