#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	int ACnt = 0, BCnt = 0;

	for (int n = 0; n < N; n++)
	{
		int A, B;
		cin >> A >> B;

		if (A > B)
		{
			ACnt++;
		}
		else if (A < B)
		{
			BCnt++;
		}
	}

	cout << ACnt << " " << BCnt << "\n";

	return 0;
}