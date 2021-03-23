#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
	int r, c;
}Coord;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Coord bessie, daisy, kahn;
	cin >> bessie.r >> bessie.c >> daisy.r >> daisy.c >> kahn.r >> kahn.c;

	int bessieDuration = max(abs(kahn.r - bessie.r), abs(kahn.c - bessie.c));
	int daisyDuration = abs(kahn.r - daisy.r) + abs(kahn.c - daisy.c);

	if (bessieDuration > daisyDuration)
	{
		cout << "daisy\n";
	}
	else if (bessieDuration == daisyDuration)
	{
		cout << "tie\n";
	}
	else
	{
		cout << "bessie\n";
	}

	return 0;
}