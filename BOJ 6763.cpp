#include <iostream>
using namespace std;

void printFine(int speedLimit, int recordedSpeed)
{
	int diff = recordedSpeed - speedLimit;
	int fine;

	if (diff <= 20)
	{
		fine = 100;
	}
	else if (diff <= 30)
	{
		fine = 270;
	}
	else
	{
		fine = 500;
	}

	cout << "You are speeding and your fine is $" << fine << ".\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int speedLimit, recordedSpeed;
	cin >> speedLimit >> recordedSpeed;

	if (recordedSpeed <= speedLimit)
	{
		cout << "Congratulations, you are within the speed limit!\n";

		return 0;
	}

	printFine(speedLimit, recordedSpeed);

	return 0;
}