#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool isPerfectSquare(long long n)
{
    if (n < 0)
    {
        return false;
    }

    long long root = sqrt(n);

    for (long long x = max(0LL, root - 1); x <= root + 1; x++)
    {
        if (x * x == n)
        {
            return true;
        }
    }

    return false;
}

long long reversedNumber(long long n)
{
    string s = to_string(n);
    reverse(s.begin(), s.end());

    return stoll(s);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) 
    {
        long long N;
        cin >> N;

        if (!isPerfectSquare(N)) 
        {
            cout << "NO\n";

            continue;
        }

        long long reverseNum = reversedNumber(N);

        if (isPerfectSquare(reverseNum))
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }
    }

    return 0;
}