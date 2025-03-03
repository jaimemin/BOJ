#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<string> matrix(N);

    for (int row = 0; row < N; row++) 
    {
        cin >> matrix[row];
    }

    string baseColumn(N, ' ');

    for (int row = 0; row < N; row++) 
    {
        baseColumn[row] = matrix[row][0];
    }

    unordered_set<string> distinctColumnSet;
    vector<string> distinctColumns;

    for (int col = 0; col < M; col++) 
    {
        string currentColumn(N, ' ');

        for (int row = 0; row < N; row++)
        {
            currentColumn[row] = matrix[row][col];
        }

        if (col == 0)
        {
            continue;
        }

        if (currentColumn != baseColumn 
            && distinctColumnSet.find(currentColumn) == distinctColumnSet.end()) 
        {
            distinctColumnSet.insert(currentColumn);
            distinctColumns.push_back(currentColumn);
        }
    }

    bool isNoFlipCandidateValid = true;
    vector<bool> validRowFlipCandidates(N, true);

    for (string otherColumn : distinctColumns)
    {
        int differenceCount = 0;
        vector<int> differenceIndices;

        for (int row = 0; row < N; row++) 
        {
            if (baseColumn[row] != otherColumn[row])
            {
                differenceCount++;
                differenceIndices.push_back(row);

                if (differenceCount > 2)
                {
                    break;
                }
            }
        }

        if (differenceCount > 2)
        {
            cout << 0 << "\n";

            return 0;
        }

        if (differenceCount == 1) 
        {
            int requiredFlipRow = differenceIndices[0];

            for (int row = 0; row < N; row++) 
            {
                if (row != requiredFlipRow)
                {
                    validRowFlipCandidates[row] = false;
                }
            }
        }
        else if (differenceCount == 2) 
        {

            isNoFlipCandidateValid = false;

            vector<bool> allowedFlipRows(N, false);
            allowedFlipRows[differenceIndices[0]] = true;
            allowedFlipRows[differenceIndices[1]] = true;

            for (int row = 0; row < N; row++) 
            {
                if (!allowedFlipRows[row])
                {
                    validRowFlipCandidates[row] = false;
                }
            }
        }
    }

    int validSingleRowFlipCount = 0;

    for (int row = 0; row < N; row++)
    {
        if (validRowFlipCandidates[row])
        {
            validSingleRowFlipCount++;
        }
    }

    int answer = (isNoFlipCandidateValid ? 1 : 0) + validSingleRowFlipCount;

    cout << answer << "\n";

    return 0;
}
