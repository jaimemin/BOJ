#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> footsteps(MAX);

	for (int i = 0; i < MAX; i++)
	{
		cin >> footsteps[i];
	}

	sort(footsteps.begin(), footsteps.end());

	int result = footsteps[0] * footsteps[2];

	cout << result << "\n";

	return 0;
}