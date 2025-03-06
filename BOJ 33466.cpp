#include <iostream>
using namespace std;

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

        long long half = N / 2;
        long long result = N + 2 * half;

        cout << result << "\n";
    }

    return 0;
}