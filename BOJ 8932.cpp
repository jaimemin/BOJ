#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 7;

typedef struct
{
	double A, B, C;
} Score;

Score score[MAX] = {
	{9.23076, 26.7, 1.835},
	{1.84523, 75, 1.348},
	{56.0211, 1.5, 1.05},
	{4.99087, 42.5, 1.81},
	{0.188807, 210, 1.41},
	{15.9803, 3.8, 1.04},
	{0.11193, 254, 1.88}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int result = 0;

		for (int i = 0; i < MAX; i++)
		{
			double P;
			cin >> P;

			if (score[i].B >= P)
			{
				result += floor((score[i].A * pow(score[i].B - P, score[i].C)));
			}
			else
			{
				result += floor((score[i].A * pow(P - score[i].B, score[i].C)));
			}
		}

		cout << result << "\n";
	}

	return 0;
}