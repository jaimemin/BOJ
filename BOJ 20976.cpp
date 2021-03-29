#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 3;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int arr[MAX];

	for (int i = 0; i < MAX; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + MAX);

	cout << arr[1] << "\n";
	
	return 0;
}