#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    int cost = 0;

    for (int i = 0; i < N; i++) 
    {
        if (i < N - 2 && A[i + 1] > A[i + 2]) 
        {
            int minRamens = min(A[i], A[i + 1] - A[i + 2]);
            cost += minRamens * 5;
            A[i] -= minRamens;
            A[i + 1] -= minRamens;
        }

        if (i < N - 2) 
        {
            int minRamens = min({ A[i], A[i + 1], A[i + 2] });
            cost += minRamens * 7;
            A[i] -= minRamens;
            A[i + 1] -= minRamens;
            A[i + 2] -= minRamens;
        }

        if (i < N - 1) 
        {
            int minRamens = min(A[i], A[i + 1]);
            cost += minRamens * 5;
            A[i] -= minRamens;
            A[i + 1] -= minRamens;
        }

        if (A[i] > 0) 
        {
            cost += A[i] * 3;
        }
    }

    cout << cost << "\n";

    return 0;
}
