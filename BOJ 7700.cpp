#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	int level = 0;
	int blocks = 0;

	while (blocks <= n)
	{
		blocks += level * level + (level + 1) * (level + 1);

		level++;
	}

	cout << level - 1 << "\n";

	return 0;
}