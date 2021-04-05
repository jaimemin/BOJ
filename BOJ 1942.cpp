#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;
const int MAX_SECOND = 60;
const int MAX_MINUTE = 60;
const int MAX_HOUR = 24;

typedef struct
{
	int hour, minute, second;
}Time;

void getTimeStruct(string input, Time &startTime, Time &endTime)
{
	startTime.hour = stoi(input.substr(0, 2));
	startTime.minute = stoi(input.substr(3, 2));
	startTime.second = stoi(input.substr(6, 2));

	endTime.hour = stoi(input.substr(9, 2));
	endTime.minute = stoi(input.substr(12, 2));
	endTime.second = stoi(input.substr(15, 2));
}

bool isTimeEqual(Time startTime, Time endTime)
{
	return startTime.hour == endTime.hour
		&& startTime.minute == endTime.minute
		&& startTime.second == endTime.second;
}

int convertTimeStructToInt(Time time)
{
	return time.hour * 10000 + time.minute * 100 + time.second;
}

void incrementTime(Time &time)
{
	time.second++;

	if (time.second == MAX_SECOND)
	{
		time.second = 0;

		time.minute++;
	}

	if (time.minute == MAX_MINUTE)
	{
		time.minute = 0;

		time.hour++;
	}

	if (time.hour == MAX_HOUR)
	{
		time.hour = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < MAX; i++)
	{
		string input;
		getline(cin, input);

		Time startTime, endTime;
		getTimeStruct(input, startTime, endTime);

		int result = 0;

		while (1)
		{
			int start = convertTimeStructToInt(startTime);
			int end = convertTimeStructToInt(endTime);

			if (start % 3 == 0)
			{
				result++;
			}

			if (isTimeEqual(startTime, endTime))
			{
				break;
			}

			incrementTime(startTime);
		}

		cout << result << "\n";
	}
}