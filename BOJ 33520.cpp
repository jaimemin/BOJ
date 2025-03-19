#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    long long minRequired = 0, maxRequired = 0;

    for (int i = 0; i < N; i++) 
    {
        long long a, b;
        cin >> a >> b;

        long long mn = min(a, b);
        long long mx = max(a, b);

        minRequired = max(minRequired, mn);
        maxRequired = max(maxRequired, mx);
    }

    cout << minRequired * maxRequired << "\n";

    return 0;
}