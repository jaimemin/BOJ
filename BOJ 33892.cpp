#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;

    if (N <= 6) 
    {
        cout << "NO\n";

        return 0;
    }

    cout << "YES\n";

    long long leftoverCount = N;
    long long pairingOperationsCount = 0;

    while (leftoverCount >= 9) 
    {
        cout << leftoverCount << " - " << (leftoverCount - 1) << "\n";

        leftoverCount -= 2;
        pairingOperationsCount++;
    }

    if (leftoverCount % 2 == 0) 
    {
        cout << "8 - 4\n";
    }

    cout << "1 + 4\n";
    cout << "5 * 5\n";
    cout << "2 + 7\n";
    cout << "3 + 6\n";
    cout << "9 * 9\n";
    cout << "81 * 25\n";

    for (long long i = 0; i < pairingOperationsCount; i++)
    {
        cout << "2025 * 1\n";
    }

    return 0;
}