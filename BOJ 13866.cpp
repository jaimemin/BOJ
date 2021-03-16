#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 4;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int scores[MAX];

	for (int i = 0; i < MAX; i++)
	{
		cin >> scores[i];
	}

	sort(scores, scores + MAX);

	int result = (scores[0] + scores[3]) - (scores[1] + scores[2]);

	cout << abs(result) << "\n";

	return 0;
}