#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;

    for (int t=0; t<T; t++)
    {
        int N, D;
        cin>>N>>D;

        int result = 0;

        for (int n=0; n<N; n++)
        {
            double v, f, c;
            cin>>v>>f>>c;

            double distance = (f / c) * v;

            result = distance >= D ? result + 1 : result; 
        }

        cout << result << "\n";
    }

    return 0;
}