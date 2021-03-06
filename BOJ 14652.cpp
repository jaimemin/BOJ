#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;


	int row = K / M;
	int col = K % M;

	cout << row << " " << col << "\n";

	return 0;
}