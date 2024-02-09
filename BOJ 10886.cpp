#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int cute = 0;

	for (int i = 0; i < N; i++)
	{
		bool opinion;
		cin >> opinion;

		cute += opinion;
	}

	cout << "Junhee is " << ((N - cute > cute) ? "not cute!\n" : "cute!\n");

	return 0;
}