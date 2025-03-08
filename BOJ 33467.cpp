#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const long long MAX_COORD = 50000000LL;

struct Point 
{
    long long x, y;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    if (N < 3) 
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<Point> pts(N);
    long long P = N - 1;
    long long t = 1;

    if (P * P > MAX_COORD)
    {
        t = (P * P + MAX_COORD - 1) / MAX_COORD;
    }

    for (int i = 0; i < N; i++) 
    {
        long long x = 2LL * i;
        long long diff = (P * P - (long long)i * i);
        long long y = diff / t;

        pts[i] = { x, y };
    }

    long double sumX = 0, sumY = 0;

    for (auto& p : pts)
    {
        sumX += p.x;
        sumY += p.y;
    }

    long double cx = sumX / N, cy = sumY / N;

    sort(pts.begin(), pts.end(), [=](const Point& a, const Point& b)
    {
        long double angA = atan2((long double)a.y - cy, (long double)a.x - cx);
        long double angB = atan2((long double)b.y - cy, (long double)b.x - cx);
            
        return angA < angB;
    });

    for (auto& p : pts)
    {
        cout << p.x << " " << p.y << "\n";
    }

    return 0;
}