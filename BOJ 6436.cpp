#include <iostream>
using namespace std;

const int MAX_FILE_SIZE = 62 * 30000;

int main(void)
{
	for (int cnt = 1; ; cnt++)
	{
		int s;
		cin >> s;

		if (s == 0)
		{
			break;
		}
		
		// Compress
		s = s % 2 ? s / 2 + 1 : s / 2;

		// decode (=unencode?)
		s += s % 2 ? s / 2 + 1 : s / 2;
		
		int floppiesCnt = (s + (MAX_FILE_SIZE - 1)) / MAX_FILE_SIZE;

		printf("File #%d\n", cnt);
		printf("John needs %d floppies.\n\n", floppiesCnt);
	}

	return 0;
}