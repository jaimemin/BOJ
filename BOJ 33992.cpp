#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double ax, ay, bx, by, px, py, r;
    cin >> ax >> ay >> bx >> by >> px >> py >> r;

    auto dist = [&](double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    double dAB = dist(ax, ay, bx, by);
    double dAP = dist(ax, ay, px, py);
    double dBP = dist(bx, by, px, py);
    double viaOasis = max(0.0, dAP - r) + max(0.0, dBP - r);
    double answer = min(dAB, viaOasis);

    cout << fixed << setprecision(10) << answer << "\n";

    return 0;
}