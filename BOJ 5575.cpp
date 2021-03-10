#include <iostream>
using namespace std;

const int MAX = 3;
const int MAX_SECOND = 60;
const int MAX_MINUTE = 60;

typedef struct
{
	int startTime[MAX];
	int endTime[MAX];
} Employee;

void printDiff(Employee employee)
{
	int hour = employee.endTime[0] - employee.startTime[0];
	int minute = employee.endTime[1] - employee.startTime[1];
	int second = employee.endTime[2] - employee.startTime[2];

	if (second < 0)
	{
		second += MAX_SECOND;
		minute--;
	}

	if (minute < 0)
	{
		minute += MAX_MINUTE;
		hour--;
	}

	cout << hour << " " << minute << " " << second << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int employeeIdx = 0; employeeIdx < MAX; employeeIdx++)
	{
		Employee employee;

		for (int startIdx = 0; startIdx < MAX; startIdx++)
		{
			cin >> employee.startTime[startIdx];
		}

		for (int endIdx = 0; endIdx < MAX; endIdx++)
		{
			cin >> employee.endTime[endIdx];
		}

		printDiff(employee);
	}

	return 0;
}