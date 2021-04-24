#include <iostream>
using namespace std;

const int MAX = 9;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 1; i <= MAX; i++)
	{
		cout << N << " * " << i << " = " << N * i << "\n";
	}
	
	return 0;
}