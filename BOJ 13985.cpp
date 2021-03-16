#include <iostream>
#include <string>
using namespace std;

const int FIRST_NUM_IDX = 0;
const int SECOND_NUM_IDX = 4;
const int RESULT_IDX = 8;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string input;
	getline(cin, input);

	int firstNum = input[FIRST_NUM_IDX] - '0';
	int secondNum = input[SECOND_NUM_IDX] - '0';
	int result = input[RESULT_IDX] - '0';

	if (firstNum + secondNum == result)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}

	return 0;
}