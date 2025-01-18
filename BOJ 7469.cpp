#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �ִ� N (�迭 ũ��)
static const int MAXN = 100000;
// ���� �ִ� ����
static const int MAXM = 5000;

// �Է� �迭 (1-based)
int a[MAXN + 1];

// ��ǥ ���� ����
int compArr[MAXN + 1];         // a[i] ���� ������ ����� ����

vector<long long> uniqVal;   // �ߺ� ���ŵ�(���ĵ�) ���� ������ ����

// ���׸�Ʈ Ʈ�� �迭 (�۽ý���Ʈ)
int leftChild[40'000'00];   // ���� �ڽ� �ε���

int rightChild[40'000'00];  // ������ �ڽ� �ε���

int segSum[40'000'00];      // �� ��尡 �����ϴ� ������ ��(����)

int root[MAXN + 1];           // �� ����(0~n)�� ��Ʈ ��� ��ȣ

int nodeCount = 0;          // ���׸�Ʈ Ʈ�� ��尡 �� �� �����������

// ���׸�Ʈ Ʈ�� build (�� Ʈ�� ����) - ��ǻ� �ʿ� ���ٸ� ���� ����
// ���⼭�� Ư���� �ʱ� �� ��带 ������ �ʿ䰡 ��� ��� X

// update(prev, start, end, pos, val):
//  ���� ���� prev Ʈ���� �����Ͽ� [pos] ��ġ�� val ���� ���ο� ��� ��ȯ
int update(int prevNode, int start, int end, int pos, int val)
{
    // �� ��� �ϳ� ����
    int curr = ++nodeCount;

    // ���� ����� ���� ����
    leftChild[curr] = leftChild[prevNode];
    rightChild[curr] = rightChild[prevNode];
    segSum[curr] = segSum[prevNode] + val;

    // ������ �ƴϸ� �ڽĵ� ��� ������Ʈ
    if (start < end)
    {
        int mid = (start + end) / 2;

        if (pos <= mid)
        {
            int newLeft = update(leftChild[prevNode], start, mid, pos, val);
            leftChild[curr] = newLeft;
        }
        else 
        {
            int newRight = update(rightChild[prevNode], mid + 1, end, pos, val);
            rightChild[curr] = newRight;
        }
    }

    return curr;
}

// query(u, v, start, end, k):
//  ���� u, v (���׸�Ʈ)�� ���̸� �̿��Ͽ�
//  ���� [start, end] ������ "k��° ��"�� ���ప�� ã�´�.
int query(int u, int v, int start, int end, int k) 
{
    // ������ �����ϸ�, start == end == "k��°�� ���� ��"�� ���� �ε���
    if (start == end) 
    {
        return start;
    }

    int mid = (start + end) >> 1;
    // ���� �ڽĿ� ����ִ� ���� ���� (���� v - ���� u)
    int leftCount = segSum[leftChild[v]] - segSum[leftChild[u]];

    if (leftCount >= k)
    {
        // ���� �ڽ����� �̵�
        return query(leftChild[u], leftChild[v], start, mid, k);
    }

    // ������ �ڽ����� �̵�, k�� ����
    return query(rightChild[u], rightChild[v], mid + 1, end, k - leftCount);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    // 1. �迭 �Է�
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];

        uniqVal.push_back(a[i]);
    }

    // 2. ��ǥ ����
    sort(uniqVal.begin(), uniqVal.end());
    uniqVal.erase(unique(uniqVal.begin(), uniqVal.end()), uniqVal.end());
    // ���� �� ����: [1 .. uniqVal.size()]

    // compArr[i] = a[i]�� ���ప
    for (int i = 1; i <= n; i++) 
    {
        // lower_bound�� ã�� �ε����� +1
        int idx = int(lower_bound(uniqVal.begin(), uniqVal.end(), a[i]) - uniqVal.begin()) + 1;

        compArr[i] = idx;
    }

    // 3. �۽ý���Ʈ ���׸�Ʈ Ʈ�� ����
    //    root[0] = 0 (�� Ʈ��)�� ����, i=1..n�� ���� ������Ʈ
    for (int i = 1; i <= n; i++)
    {
        root[i] = update(root[i - 1], 1, (int)uniqVal.size(), compArr[i], 1);
    }

    // 4. ���� ó��
    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;
        // i..j �������� k��° ���� ��
        // => query(root[i-1], root[j], 1, size, k)
        // (����) i=1�� ��, root[0]�� �� Ʈ��

        int compIndex = query(root[i - 1], root[j], 1, (int)uniqVal.size(), k);
        // compIndex�� ���� ������ ����ȯ
        long long answer = uniqVal[compIndex - 1]; // ���ʹ� 0-based

        cout << answer << "\n";
    }

    return 0;
}