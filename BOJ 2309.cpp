#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 7;

const int INPUT_MAX = 9;

const int MAX_HEIGHT = 100;

int answer[MAX];

void func(int idx, int total, vector<int>& heights)
{
	if (idx == MAX && total == MAX_HEIGHT)
	{
		for (int i = 0; i < MAX; i++)
		{
			cout << answer[i] << "\n";
		}

		exit(0);
	}

	for (int i = idx; i < INPUT_MAX; i++)
	{
		answer[idx] = heights[i];
		func(idx + 1, total + answer[idx], heights);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> heights;
	
	for (int i = 0; i < INPUT_MAX; i++)
	{
		int height;
		cin >> height;

		heights.push_back(height);
	}

	sort(heights.begin(), heights.end());

	func(0, 0, heights);

	return 0;
}