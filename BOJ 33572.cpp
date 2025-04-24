#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, M;
    cin >> N >> M;
    long long answer = 0;

    for (long long i = 0; i < N; i++)
    {
        long long A;
        cin >> A;

        answer += (A - 1);

        if (answer >= M) 
        {
            for (long long j = i + 1; j < N; j++) 
            {
                cin >> A;
            }

            cout << "DIMI\n";

            return 0;
        }
    }

    cout << "OUT\n";

    return 0;
}