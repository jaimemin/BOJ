#include <iostream>
using namespace std;

const int MAX = 10e6;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	int arr[MAX];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int num = 1;
	int removedCnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] != num)
		{
			removedCnt++;
			
			continue;
		}

		num++;
	}

	cout << removedCnt << "\n";

	return 0;
}