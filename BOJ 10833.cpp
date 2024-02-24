#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		int students, apples;
		cin >> students >> apples;

		sum += (apples % students);
	}

	cout << sum << "\n";

	return 0;
}