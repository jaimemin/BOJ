#include <iostream>
#include <cmath>
using namespace std;

long long boardingTime(long long d, long long t)
{
    if (d % t == 0)
    {
        return d;
    }

    return (d / t + 1) * t;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int Q;
    cin >> Q;

    while (Q--) 
    {
        long long x, y, t1, t2, t3;
        cin >> x >> y >> t1 >> t2 >> t3;

        long long d1 = llabs(x - x1) + llabs(y - y1);
        long long d2 = llabs(x - x2) + llabs(y - y2);
        long long d3 = llabs(x - x3) + llabs(y - y3);
        long long result = min({ boardingTime(d1, t1), boardingTime(d2, t2), boardingTime(d3, t3) });

        cout << result << "\n";
    }

    return 0;
}