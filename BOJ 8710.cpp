#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long k, w, m;
	cin >> k >> w >> m;

	long long result = 0;

	while (k < w)
	{
		k += m;
		
		result++;
	}

	cout << result << "\n";

	return 0;
}