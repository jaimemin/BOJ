#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e6;

vector<vector<long long>> multiplyMatrix(const vector<vector<long long>>& a, const vector<vector<long long>>& b)
{
    vector<vector<long long>> result(2, vector<long long>(2));
    result[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    result[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    result[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    result[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;

    return result;
}

vector<vector<long long>> powerMatrix(vector<vector<long long>> base, long long exp) 
{
    vector<vector<long long>> result = { {1, 0}, {0, 1} };

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = multiplyMatrix(result, base);
        }

        base = multiplyMatrix(base, base);
        exp /= 2;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<long long>> base = { {1, 1}, {1, 0} };
    vector<vector<long long>> result = powerMatrix(base, n - 1);

    cout << result[0][0] << "\n";

    return 0;
}
