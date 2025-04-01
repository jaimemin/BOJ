#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, D, K;
    cin >> N >> D >> K;

    vector<int> s(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> s[i];
    }

    int m = K / s[0];

    for (int i = 1; i < N; i++)
    {
        m = min(m, K / s[i]);
    }

    int segments = (D + m - 1) / m;
    int cleaningCount = segments - 1;

    cout << cleaningCount << "\n";

    return 0;
}