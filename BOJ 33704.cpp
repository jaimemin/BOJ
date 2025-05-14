#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<long long> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    if (N >= 3) 
    {
        cout << "YES\n";
    }
    else 
    {
        cout << (A[0] <= A[1] ? "YES" : "NO") << "\n";
    }

    return 0;
}