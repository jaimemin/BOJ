#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, W, H;
	cin >> N >> W >> H;

	int longestLength = W * W + H * H;

	for (int i = 0; i<N; i++)
	{
		int matchLength;
		cin >> matchLength;

		if (matchLength * matchLength <= longestLength)
		{
			cout << "DA\n";
		}
		else
		{
			cout << "NE\n";
		}
	}

	return 0;
}