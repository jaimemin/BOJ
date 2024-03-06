#include <iostream>
#include <string>
using namespace std;

const int MAX = 26;

int alphabets[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;

		alphabets[name[0] - 'a']++;
	}

	bool flag = false;

	for (int i = 0; i < MAX; i++)
	{
		if (alphabets[i] >= 5)
		{
			cout << (char)('a' + i);
			
			flag = true;
		}
	}

	if (!flag)
	{
		cout << "PREDAJA\n";
	}

	return 0;
}