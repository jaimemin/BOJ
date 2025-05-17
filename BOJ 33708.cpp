#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    bool nondecreasing = true;

    for (int i = 0; i + 1 < N; i++)
    {
        if (A[i] > A[i + 1])
        {
            nondecreasing = false;

            break;
        }
    }

    if (nondecreasing)
    {
        cout << "YES\n";

        return 0;
    }

    int maxA = 0;

    for (int x : A)
    {
        maxA = max(maxA, x);
    }

    vector<bool> isPrime(maxA + 1, true);

    if (maxA >= 0)
    {
        isPrime[0] = false;
    }

    if (maxA >= 1)
    {
        isPrime[1] = false;
    }

    for (int i = 2; 1LL * i * i <= maxA; i++)
    {
        if (!isPrime[i])
        {
            continue;
        }

        for (int j = i * i; j <= maxA; j += i)
        {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i + 1 < N; i++) 
    {
        int x = A[i], y = A[i + 1];
        bool locked = false;

        if (x == 1 && y == 1)
        {
            locked = true;
        }
        else if (x == 1 && isPrime[y]) 
        {
            locked = true;
        }
        else if (y == 1 && isPrime[x])
        {
            locked = true;
        }

        if (!locked) 
        {
            cout << "YES\n";

            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}