#include <iostream>
using namespace std;

bool canBeWideReceiver(double speed, int weight, int strength)
{
	return (speed <= 4.5 && weight >= 150 && strength >= 200);
}

bool canBeLineman(double speed, int weight, int strength)
{
	return (speed <= 6.0 && weight >= 300 && strength >= 500);
}

bool canBeQuarterback(double speed, int weight, int strength)
{
	return (speed <= 5.0 && weight >= 200 && strength >= 300);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		double speed;
		int weight, strength;
		cin >> speed >> weight >> strength;

		if (speed == 0.00 && weight == 0 && strength == 0)
		{
			break;
		}

		int cnt = 0;

		if (canBeWideReceiver(speed, weight, strength))
		{
			cnt++;
			cout << "Wide Receiver ";
		}
		
		if (canBeLineman(speed, weight, strength))
		{
			cnt++;
			cout << "Lineman ";
		}

		if (canBeQuarterback(speed, weight, strength))
		{
			cnt++;
			cout << "Quarterback ";
		}

		if (cnt == 0)
		{
			cout << "No positions";
		}

		cout << "\n";
	}

	return 0;
}