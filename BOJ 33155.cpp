#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���Ѵ� ǥ��
const long long NEG_INF = -0x3f3f3f3f3f3f3f3fLL;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<long long> A(N), V(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }

    vector<long long> B(M);

    for (int j = 0; j < M; j++) 
    {
        cin >> B[j];
    }

    for (int i = 0; i < N; i++) 
    {
        cin >> V[i];
    }

    // ���� C[i][j]
    vector<vector<long long>> C(N, vector<long long>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> C[i][j];
        }
    }

    // ------------------------------------------------------------
    // 1) �ٱ��ϰ� M > N �̸�, ���� ū �ٱ��� N���� ���� �� (���� M�� ���� �� �ᵵ ��)
    //    -> B[] �������� ���� �� ���� N���� slice
    if (M > N)
    {
        sort(B.begin(), B.end(), greater<long long>());
        B.resize(N);
        M = N;
    }
    else 
    {
        // M <= N�� ��쿣 �׳� �ᵵ ��. (�������� ���������� �صֵ� ��)
        sort(B.begin(), B.end(), greater<long long>());
    }
    // ���� B[0], B[1], ..., B[M-1] �� ����� ���� (M <= N)

    // ------------------------------------------------------------
    // 2) �κ����� ��ó��: �� subset s �� ����,
    //    - sizeS[s] = sum(A_i)   (�� ũ�� ��)
    //    - valueS[s] = sum(V_i)  (�� ��ġ ��)
    //    - beautyS[s] = sum of C[i][j] (i<=j, i,j in s)
    //      (�� ���� ��, "�Ƹ��ٿ�")
    int fullMask = (1 << N);
    vector<long long> sizeS(fullMask, 0LL);
    vector<long long> valueS(fullMask, 0LL);
    vector<long long> beautyS(fullMask, 0LL);

    // �κ����ո��� A,V ��
    for (int s = 0; s < fullMask; s++)
    {
        long long sumA = 0, sumV = 0;

        for (int i = 0; i < N; i++) 
        {
            if (s & (1 << i))
            {
                sumA += A[i];
                sumV += V[i];
            }
        }

        sizeS[s] = sumA;
        valueS[s] = sumV;
    }

    // �κ����ո��� C ��(beauty)
    // N=15������, s=0..(1<<N)-1 �� ���� i,j ��ø(�ִ� 15*15*2^15 = 450k ����)�̸� ����
    for (int s = 0; s < fullMask; s++) 
    {
        long long sumC = 0;
        // i <= j �� ��� (i,j)�� ����, i,j�� s�� ���ϸ� C[i][j] ����
        // (�Ʒ�ó�� ���� ���� for������ �ص� ������, �� ���� ����� ����)
        for (int i = 0; i < N; i++) 
        {
            if (s & (1 << i)) 
            {
                for (int j = i; j < N; j++)
                {
                    if (s & (1 << j)) 
                    {
                        sumC += C[i][j];
                    }
                }
            }
        }

        beautyS[s] = sumC;
    }

    // ------------------------------------------------------------
    // 3) DP �迭: dp[state][i]
    //    state: (����) �ɵ��� ����, i: ���� �ٱ��� �ε��� (0..M)
    //    ũ�� = 2^N x (M+1)
    static long long dp[1 << 15][16]; // N �ִ� 15, M <= N �̹Ƿ� (M+1) <= 16
    // base case: dp[state][M] = 0 (�� �̻� �ٱ��ϰ� ������ �ƹ��͵� ���� �� ����)
    // �������� -�ķ� �ʱ�ȭ

    for (int s = 0; s < fullMask; s++) 
    {
        for (int i = 0; i <= M; i++)
        {
            dp[s][i] = NEG_INF;
        }

        dp[s][M] = 0;
    }

    // �ٱ��ϸ� �ڿ������� ������( i=M-1 down to 0 ) ä�������� Bottom-Up
    for (int i = M - 1; i >= 0; i--) 
    {
        for (int s = 0; s < fullMask; s++) 
        {
            // 1) �� �ٱ���(i)�� �� ���� ���
            long long ret = dp[s][i + 1];

            // 2) �� �ٱ���(i)�� ���� ���
            //    s�� �κ����� �� (sizeS[sub] <= B[i]) && (valueS[sub] <= K)�� sub�� ��� ���,
            //    ���� �� s ^ sub �� �ٲ�
            //    ��� �Ƹ��ٿ��� beautyS[sub], ���� dp[s^sub][ i+1 ]
            //    sub != 0 �̾�� "�ϳ� �̻� ���� ��Ҵ�"�� ������ ����������,
            //    ���� ���� ���� "�ش� �ٱ��ϸ� ���� �� ����" �͵� �̹� 1)���� Ŀ���ǹǷ�
            //    ���⼱ sub=0�� ���� ������ �ʿ䰡 ���ų�, Ȥ�� �����ص� �˴ϴ�.
            //    (�ٸ� '�� �ٱ���'�� �Ƹ��ٿ� �⿩=0�̹Ƿ� ��ǻ� �� 1)�� ����)

            // s�� ��� �κ����� sub�� ��ȸ -> O(2^|s|)
            // ��, |s|�ִ� 15�� �� ������ �־ǿ� 2^15 = 32768.
            // s=0�� ���� �κ����� 1��(0)��.
            // ��ü s�� ���� 2^N x 2^N = 4^N = 4^15 ~ 1.07e9, ���� ����ȭ �ʿ�.

            // �κ����� ���� ���: 
            //   for(int sub = s; ; sub = (sub-1) & s) { ... if(sub==0) break; }
            // 
            // �Ǵ� 0���� s���� ��� mask �� (mask & s) == mask �� üũ
            // ���⼭�� �Ϲ����� ���(sub = (sub-1) & s)�� ���


            // sub=0..(����) ��ȸ�� ����ϵ��� do-while ���� ����
            int sub = s;

            do 
            {
                // ���� üũ
                if (sizeS[sub] <= B[i] && valueS[sub] <= K) 
                {
                    long long candidate = beautyS[sub] + dp[s ^ sub][i + 1];

                    if (candidate > ret)
                    {
                        ret = candidate;
                    }
                }

                sub = (sub - 1) & s;
            } while (sub != s);

            dp[s][i] = ret;
        }
    }

    // ��: dp[(1<<N)-1][0]
    cout << dp[(1 << N) - 1][0] << "\n";

    return 0;
}