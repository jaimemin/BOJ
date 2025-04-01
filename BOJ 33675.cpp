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
        int N;
        cin >> N;

        cout << (N % 2 == 0 ? (1LL << (N / 2)) : 0) << "\n";
    }

    return 0;
}