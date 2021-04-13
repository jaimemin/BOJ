#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (int j = i; j < N; j++)
		{
			cout << "*";
		}
		
		cout << "\n";
	}

	return 0;
}