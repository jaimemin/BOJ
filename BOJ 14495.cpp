#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    if (n <= 3)
    {
        cout << 1 << "\n";

        return 0;
    }

    vector<int> sequence(n + 1);
    
    for (int i = 1; i <= 3; i++)
    {
        sequence[i] = 1;
    }

    for (int i = 4; i <= n; i++) 
    {
        sequence[i] = sequence[i - 1] + sequence[i - 3];
    }

    cout << sequence[n] << "\n";

    return 0;
}
