#include <iostream>
using namespace std;

const int MAX = 3;
const int TRIANGLE_ANGLE_SUM = 180;

void printResult(int angles[MAX])
{
	// 정삼각형
	if (angles[0] == angles[1] 
		&& angles[1] == angles[2])
	{
		cout << "Equilateral\n";

		return;
	}

	// 두 각이 같은 경우
	if (angles[0] == angles[1] 
		|| angles[1] == angles[2] 
		|| angles[2] == angles[0])
	{
		cout << "Isosceles\n";

		return;
	}

	cout << "Scalene\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int angles[MAX];

	int sum = 0;

	for (int i = 0; i < MAX; i++)
	{
		cin >> angles[i];

		sum += angles[i];
	}
	
	if (sum != TRIANGLE_ANGLE_SUM)
	{
		cout << "Error\n";

		return 0;
	}

	printResult(angles);

	return 0;
}