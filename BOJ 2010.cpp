#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int result = 0;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		result += (i == 0 ? num : num - 1);
	}

	cout << result << "\n";

	return 0;
}