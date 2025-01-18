#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Precompute f(x) and g(x)
    vector<long long> f(MAX + 1, 0);
    vector<long long> g(MAX + 1, 0);

    for (int i = 1; i <= MAX; i++)
    {
        for (int j = i; j <= MAX; j += i)
        {
            f[j] += i;
        }
    }

    for (int i = 1; i <= MAX; i++) 
    {
        g[i] = g[i - 1] + f[i];
    }

    // Process test cases
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        cout << g[N] << '\n';
    }

    return 0;
}