#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M, N;
	cin >> M >> N;

	int sum = 0;
	int answer = 1e4 + 1;

	for (int i = M; i <= N; i++)
	{
		int root = sqrt(i);

		if (root * root == i)
		{
			sum += i;
			answer = min(answer, i);
		}
	}

	cout << (sum == 0 ? -1 : sum) << "\n";

	if (sum)
	{
		cout << answer << "\n";
	}

	return 0;
}