#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MINUTE = 60;
const int MINUTE2SECOND = 60;
const int HOUR = 24;
const int HOUR2SECOND = 3600;

typedef struct
{
	int hour, minute, second;
} Time;

Time getTime(string time)
{
	size_t pos = time.find(':', 0);
	size_t pos2 = time.find(':', pos + 1);

	// Ω√ ∫– √ 
	Time temp = { stoi(time.substr(0, pos))
		, stoi(time.substr(pos + 1, pos2))
		, stoi(time.substr(pos2 + 1)) };
	
	return temp;
}

void printDiff(string startTime, string endTime)
{
	Time start = getTime(startTime);
	Time end = getTime(endTime);

	int second = end.second - start.second;
	int minute = end.minute - start.minute;
	int hour = end.hour - start.hour;

	if (second < 0)
	{
		minute--;

		second += MINUTE2SECOND;
	}

	if (minute < 0)
	{
		hour--;

		minute += MINUTE;
	}

	if (hour < 0)
	{
		hour += HOUR;
	}

	int result = hour * HOUR2SECOND + minute * MINUTE2SECOND + second;

	cout << result << "\n";
}

string removeBlankSpace(string time)
{
	time.erase(remove(time.begin(), time.end(), ' '), time.end());

	return time;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string startTime, endTime;
	getline(cin, startTime);
	getline(cin, endTime);

	startTime = removeBlankSpace(startTime);
	endTime = removeBlankSpace(endTime);

	printDiff(startTime, endTime);

	return 0;
}