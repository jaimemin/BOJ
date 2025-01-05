#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50 + 5;

int result;

int buildings[MAX];

int visible[MAX];

int main(void) 
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> buildings[i];
	}

	for (int i = 0; i < N; i++)
	{
		double maxLevel = -1e18;

		for (int j = i + 1; j < N; j++) 
		{
			double level = (double)(buildings[j] - buildings[i]) / (j - i);

			if (level > maxLevel)
			{
				visible[i]++;
				visible[j]++;
				maxLevel = level;
			}
		}
	}

	for (int v : visible)
	{
		result = max(result, v);
	}

	cout << result << "\n";

	return 0;
}
