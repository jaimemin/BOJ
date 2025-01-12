#include <iostream>
using namespace std;

int countSetBits(long long x) 
{
    int cnt = 0;

    while (x)
    {
        cnt += (x % 2);

        x /= 2;
    }

    return cnt;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    int K;
    cin >> N >> K;

    if (N <= K) 
    {
        cout << 0 << "\n";

        return 0;
    }

    long long answer = 0;

    while (true) 
    {
        if (countSetBits(N) <= K) 
        {
            cout << answer << "\n";

            break;
        }

        long long lowest = (N & -N);
        answer += lowest;
        N += lowest;
    }

    return 0;
}
