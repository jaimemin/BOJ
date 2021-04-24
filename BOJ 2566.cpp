#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;

typedef struct
{
	int value;
	pair<int, int> coord;
}Number;

bool cmp(Number a, Number b)
{
	return a.value > b.value;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Number arr[MAX * MAX];
	int idx = 0;

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			int value;
			cin >> value;

			arr[idx++] = { value, {i, j} };
		}
	}

	sort(arr, arr + MAX * MAX, cmp);

	Number result = arr[0];

	cout << result.value << "\n";
	cout << result.coord.first << " " << result.coord.second << "\n";

	return 0;
}