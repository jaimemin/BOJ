#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		double price;
		cin >> price;
		
		double result = price * 0.8;

		printf("$%.2lf\n", result);
	}

	return 0;
}