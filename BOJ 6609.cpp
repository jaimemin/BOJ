#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string input;

	while (getline(cin, input))
	{
		stringstream inputStream(input);
		
		int M, P, L, E, R, S, N;
		inputStream >> M >> P >> L >> E >> R >> S >> N;

		vector<int> larvas, cocoons, mosquitos;
		larvas.push_back(L);
		cocoons.push_back(P);
		mosquitos.push_back(M);

		for (int i = 0; i < N; i++)
		{
			P = larvas.back() / R;
			M = cocoons.back() / S;
			L = mosquitos.back() * E;

			larvas.push_back(L);
			cocoons.push_back(P);
			mosquitos.push_back(M);
		}

		int result = mosquitos.back();

		cout << result << "\n";
	}

	return 0;
}