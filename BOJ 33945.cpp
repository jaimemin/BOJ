#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int addMOD(int a, int b) 
{ 
    a += b; 
    
    if (a >= MOD)
    {
        a -= MOD;
    }
    
    return a;
}

int subMOD(int a, int b) 
{ 
    a -= b; 
    
    if (a < 0)
    {
        a += MOD;
    }
    
    return a;
}

pair<int, int> digitInterval(int len) 
{
    if (len == 1)
    {
        return { 0, 9 };
    }

    int p = 1;

    for (int i = 1; i < len; ++i)
    {
        p *= 10;
    }

    return { p, p * 10 - 1 };
}

void applyInterval(vector<int>& dp, vector<int>& dst,
    int offset, int L, int R)
{
    int sz = dp.size();
    static vector<int> pref;
    pref.resize(sz + 1);
    pref[0] = 0;

    for (int i = 0; i < sz; i++)
    {
        pref[i + 1] = addMOD(pref[i], dp[i]);
    }

    for (int i = 0; i < sz; i++) 
    {
        int val = i - offset;
        int leftVal = val - R;
        int rightVal = val - L;
        int li = max(0, leftVal + offset);
        int ri = min(sz - 1, rightVal + offset);

        if (li > ri)
        {
            dst[i] = 0;
        }
        else 
        {
            dst[i] = subMOD(pref[ri + 1], pref[li]);
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<vector<vector<int>>> compositions(M + 1);

    for (int k = 1; k <= (M + 1) / 2; k++)
    {
        int need = M - (k - 1);
        vector<int> cur;

        function<void(int, int)> dfs = [&](int rem, int left) 
        {
            if (left == 1) 
            {
                cur.push_back(rem);
                compositions[k].push_back(cur);
                cur.pop_back();

                return;
            }

            for (int d = 1; d <= rem - (left - 1); d++)
            {
                cur.push_back(d);
                dfs(rem - d, left - 1);
                cur.pop_back();
            }
        };

        dfs(need, k);
    }

    int answer = 0;

    for (int k = 1; k <= (M + 1) / 2; k++) 
    {
        for (auto& lens : compositions[k])
        {
            int signChoices = 1 << (k - 1);

            for (int mask = 0; mask < signChoices; mask++)
            {
                vector<int> signs(k, 1);

                for (int i = 1; i < k; i++)
                {
                    signs[i] = (mask >> (i - 1) & 1) ? -1 : +1;
                }

                int idxBig = 0;

                for (int i = 1; i < k; i++)
                {
                    if (lens[i] > lens[idxBig]) idxBig = i;
                }

                auto ivBig = digitInterval(lens[idxBig]);
                int Lbig = ivBig.first;
                int Rbig = ivBig.second;
                int sBig = signs[idxBig];
                int bound = 0;

                for (int i = 0; i < k; i++) 
                {
                    if (i != idxBig)
                    {
                        int mx = digitInterval(lens[i]).second;
                        bound += mx;
                    }
                }

                vector<int> dp(2 * bound + 1, 0), tmp(2 * bound + 1, 0);
                int off = bound;
                dp[off] = 1;

                for (int i = 0; i < k; i++) 
                {
                    if (i != idxBig) 
                    {
                        auto iv = digitInterval(lens[i]);
                        int L = iv.first;
                        int R = iv.second;

                        if (signs[i] == -1) 
                        {
                            L = -R; 
                            R = -iv.first;
                        }

                        fill(tmp.begin(), tmp.end(), 0);
                        applyInterval(dp, tmp, off, L, R);
                        dp.swap(tmp);
                    }
                }

                for (int v = Lbig; v <= Rbig; v++)
                {
                    int need = N - sBig * v;

                    if (need < -bound || need > bound)
                    {
                        continue;
                    }

                    answer = addMOD(answer, dp[need + off]);
                }
            }
        }
    }

    cout << answer % MOD << "\n";

    return 0;
}