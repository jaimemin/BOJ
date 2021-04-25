#include <iostream>
using namespace std;

int pow(int p)
{
	int result = 1;

	for (int i = 0; i < p; i++)
	{
		result *= 2;
	}
	
	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int side = 2;

	for (int i = 0; i < N; i++)
	{
		side += pow(i);
	}

	int result = side * side;

	cout << result << "\n";

	return 0;
}