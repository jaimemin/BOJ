#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string KDA;
	cin >> KDA;

	size_t pos = KDA.find('/', 0);
	vector<int> slashIdxs;

	while (pos != string::npos)
	{
		slashIdxs.push_back(pos);

		pos = KDA.find('/', pos + 1);
	}

	int K = stoi(KDA.substr(0, slashIdxs[0]));
	int D = stoi(KDA.substr(slashIdxs[0] + 1, slashIdxs[1] - slashIdxs[0] + 1));
	int A = stoi(KDA.substr(slashIdxs[1] + 1));

	if (K + A < D || D == 0)
	{
		cout << "hasu\n";
	}
	else
	{
		cout << "gosu\n";
	}
	
	return 0;
}