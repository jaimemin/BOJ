#include <iostream>
using namespace std;

const int TARGET = 512;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    int best = 1e9;

    for (int i = 0; i < N; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        int sum = A + B + C;

        if (sum >= TARGET && sum < best)
        {
            best = sum;
        }
    }

    if (best == 1e9) 
    {
        cout << -1 << "\n";
    }
    else 
    {
        cout << best << "\n";
    }

    return 0;
}