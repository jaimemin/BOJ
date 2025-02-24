#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    double fraction = static_cast<double>(M) / N;
    int totalMinutes = static_cast<int>(fraction * 1440);

    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << "\n";

    return 0;
}