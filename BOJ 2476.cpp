#include <iostream>
#include <algorithm>
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
		int a, b, c;
		cin >> a >> b >> c;

		int temp = 0;

		if (a == b && b == c)
		{
			temp = a * 1000 + 10000;

			result = max(result, temp);

			continue;
		}

		if (a == b || b == c)
		{
			temp = b * 100 + 1000;

			result = max(result, temp);
		}

		if (c == a)
		{
			temp = a * 100 + 1000;

			result = max(result, temp);
		}

		temp = max({ a, b, c }) * 100;

		result = max(result, temp);
	}

	cout << result << "\n";

	return 0;
}