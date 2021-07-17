#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 3;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (1)
	{
		int N;
		cin >> N;

		if (N == 0)
		{
			break;
		}

		int P;
		cin >> P;

		vector<int> pages;
		pages.push_back(P % 2 ? P + 1 : P - 1);
		pages.push_back(P % 2 ? N - P : N - P + 1);
		pages.push_back(P % 2 ? N - P + 1 : N - P + 2);

		sort(pages.begin(), pages.end());

		for (int page : pages)
		{
			cout << page << " ";
		}
		cout << "\n";
	}

	return 0;
}