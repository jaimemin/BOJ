#include <iostream>
using namespace std;

typedef struct
{
	int year, month, day;
}Date;

void printManAge(Date birth, Date current)
{
	int age = current.year - birth.year;

	if (current.month < birth.month)
	{
		age--;
	}

	if (current.month == birth.month)
	{
		if (current.day < birth.day)
		{
			age--;
		}
	}

	cout << age << "\n";
}

void printSeNeunAge(Date birth, Date current)
{
	int age = current.year - birth.year + 1;

	cout << age << "\n";
}

void printYeonAge(Date birth, Date current)
{
	int age = current.year - birth.year;

	cout << age << "\n";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Date birthDate, currentDate;
	cin >> birthDate.year >> birthDate.month >> birthDate.day;
	cin >> currentDate.year >> currentDate.month >> currentDate.day;

	printManAge(birthDate, currentDate);
	printSeNeunAge(birthDate, currentDate);
	printYeonAge(birthDate, currentDate);

	return 0;
}