#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, M;
    cin >> N >> M;

    long long K = min(N - 1, M - 1);
    long long answer;

    if (N != M) 
    {
        answer = K * K;
    }
    else 
    {
        answer = (K - 1) * (K - 1) + 1;
    }

    cout << answer << "\n";

    return 0;
}