#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    int parity = ((long long)N * M) % 2 == 0 ? 0 : 1;
    vector<pair<int, int>> probes;

    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= M; c++) 
        {
            if ((r + c) % 2 == parity) 
            {
                probes.push_back(r, c);
            }
        }
    }

    for (auto [r, c] : probes)
    {
        cout << "? " << r << " " << c << "\n" << flush;

        int response;
        cin >> response;

        if (response == 1) 
        {
            return 0;
        }
    }

    return 0;
}