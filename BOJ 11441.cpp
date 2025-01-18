#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> A(N + 1, 0);

    for (int i = 1; i <= N; i++) 
    {
        int num;
        cin >> num;

        A[i] = A[i - 1] + num; // Build prefix sum array
    }

    int M;
    cin >> M;

    while (M--)
    {
        int i, j;
        cin >> i >> j;

        cout << A[j] - A[i - 1] << '\n';
    }

    return 0;
}