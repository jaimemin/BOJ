#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int n = 0; n < N; n++)
	{
		int r, e, c;
		cin >> r >> e >> c;

		if (r < e - c)
		{
			cout << "advertise\n";
		}
		else if (r == e - c)
		{
			cout << "does not matter\n";
		}
		else
		{
			cout << "do not advertise\n";
		}
	}

	return 0;
}