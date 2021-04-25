#include <iostream>
using namespace std;

const int MAX = 2;
const int MAX_ROTATION = 4;

void rotate(double (*arr)[MAX])
{
	double temp[MAX][MAX];

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			temp[j][MAX - (i + 1)] = arr[i][j];
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			arr[i][j] = temp[i][j];
		}
	}
}

double getScore(double arr[][MAX])
{
	return arr[0][0] / arr[1][0] + arr[0][1] / arr[1][1];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double arr[MAX][MAX];

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cin >> arr[i][j];
		}
	}

	double maxScore = 0.0;
	int result = 0;

	for (int i = 0; i < MAX_ROTATION; i++)
	{
		if (getScore(arr) > maxScore)
		{
			maxScore = getScore(arr);

			result = i;
		}

		rotate(arr);
	}

	cout << result << "\n";

	return 0;
}