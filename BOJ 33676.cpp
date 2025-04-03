#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K, L;
    cin >> N >> M >> K >> L;

    for (int i = 0; i < K; i++) 
    {
        int r, c;
        cin >> r >> c;
    }

    int minMoves = (N - 1) + (M - 1);

    if (L < minMoves || ((L - minMoves) % 2 != 0)) 
    {
        cout << -1 << "\n";

        return 0;
    }

    int extra = L - minMoves;
    string answer = "";

    for (int i = 0; i < extra / 2; i++) 
    {
        answer += "RL";
    }

    for (int i = 0; i < N - 1; i++)
    {
        answer += "D";
    }

    for (int j = 0; j < M - 1; j++) 
    {
        answer += "R";
    }

    cout << answer << "\n";

    return 0;
}