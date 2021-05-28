#include <iostream>
using namespace std;

const int MAX = 1000 + 10;

typedef struct
{
	int destination, rotation;
} Pully;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	Pully pullies[MAX];

	for (int i = 0; i < N - 1; i++)
	{
		int source, destination, rotation;
		cin >> source >> destination >> rotation;

		pullies[source] = { destination, rotation };
	}

	int result = 0;
	int start = 1;

	for (int i = 0; i < N - 1; i++)
	{
		result = pullies[start].rotation == 0 ? result : 1 - result;
		start = pullies[start].destination;
	}

	cout << result << "\n";

	return 0;
}