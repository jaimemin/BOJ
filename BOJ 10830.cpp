#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000;

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& a, const vector<vector<int>>& b, int n) 
{
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++) 
            {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return result;
}

vector<vector<int>> matrixPower(vector<vector<int>>& matrix, long long exponent, int n) 
{
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) 
    {
        result[i][i] = 1;
    }

    while (exponent > 0)
    {
        if (exponent % 2 == 1) 
        {
            result = multiplyMatrices(result, matrix, n);
        }

        matrix = multiplyMatrices(matrix, matrix, n);
        exponent /= 2;
    }

    return result;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long b;
    cin >> n >> b;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = matrixPower(matrix, b, n);

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}
