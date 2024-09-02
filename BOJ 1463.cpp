#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 1e3;

int cache[MAX];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i++) 
    {
        cache[i] = cache[i - 1] + 1;

        if (i % 2 == 0) 
        {
            cache[i] = min(cache[i], cache[i / 2] + 1);
        }

        if (i % 3 == 0) 
        {
            cache[i] = min(cache[i], cache[i / 3] + 1);
        }
    }

    cout << cache[n] << "\n";

    return 0;
}
