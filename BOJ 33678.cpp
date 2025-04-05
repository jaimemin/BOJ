#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2e5 + 2e2;

int N, X;

long long K;

int P[MAX];

bool func(int S)
{
    for (int j = 0; j <= N - S; j++) 
    {
        if ((long long)X * P[j] - P[j + S] >= (K - P[N]))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K >> X;

    vector<int> a(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++)
    {
        P[i] = P[i - 1] + a[i - 1];
    }

    int low = 1, high = N - 1;
    int answer = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (func(mid))
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}