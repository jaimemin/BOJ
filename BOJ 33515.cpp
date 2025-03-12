#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T1, T2;
    cin >> T1 >> T2;

    cout << min(T1, T2) << "\n";

    return 0;
}
