#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    if (N < 3)
    {
        cout << -1 << "\n";

        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        long long x = i;
        long long y = i * (i + 1) * 1LL / 2;

        cout << x << " " << y << "\n";
    }

    return 0;
}
