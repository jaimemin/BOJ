#include <iostream>
#include <algorithm>
using namespace std;

static const int MAXN = 200000;        // �ִ� Q

static const int LOGN = 20;           // log2(200000) ~= 18~19 ����

// LCA�� ���� �ڷᱸ��
// lca[v][k] = v�� 2^k��° ����
int parentArr[MAXN + 2][LOGN];

long long depthArr[MAXN + 2];  // root(1��)���κ����� �Ÿ�

int Q;

// LCA(�ּҰ�������) ���ϱ�
int getLCA(int a, int b) 
{
    if (a == b)
    {
        return a;
    }

    // ���̰� �ٸ� ��� depth ���߱�
    if (depthArr[a] < depthArr[b])
    {
        swap(a, b);
    }

    // 1) a�� depth�� b�� ���� �ø���.
    long long diff = depthArr[a] - depthArr[b];
    // ���� ���� �� ������(����ġ�� �ƴ϶� 'Ʈ�� ����' ����)�� ���� �ƴ϶�,
    // ���⼱ "����"�� '��Ʈ~�������� �Ÿ�'�� �����Ƿ� �ܼ��� diff��ŭ �����ؼ� �� �˴ϴ�.
    // ------
    // ������ "LCA ���̺�"������ parentArr[..]�� 'Ʈ�� ���� ����(1�ܰ� ����)'�� �ƴ϶�
    // '���� 2^k��° ����'�� �����ߴٰ� �� ��,
    // ����(Ʈ�� ����) ��ü�� �ƴ϶�, "2^k�� ����"�� ��� ���������� �ٸ� ������ �˴ϴ�.
    // ------
    // �Ϲ������δ� "Ʈ���� ����" (��Ʈ���� ���� ����)�� �Ἥ ó���ϴ� ���� �����Դϴ�.
    // ���⼭�� depthArr[a]�� "��Ʈ~a������ ���� ����ġ"�� ����ϴ�.
    // ��, ����ġ ������ ���ǵ� depthArr������ '����'�� �ƴ϶� �ܼ��� �Ÿ��̹Ƿ�
    // '2^k' ������ ���� ���� ���� ��ƽ��ϴ�.
    //
    // => ����, ���� ����ġ Ʈ������ "LCA�� ���� ��"��
    //    parentArr[a][k] = a�� 2^k��° '����(�θ��� �θ�...)' (Ʈ�� �����μ�)
    //    ����(���� ��) �������δ� a���� ���� 2^k�� �ö� ���.
    // => �׷� "a�� b�� (Ʈ����) ����"�� ���ߴ� ������ ���� �ؾ� �մϴ�.
    //    ����[a] = ����[parent[a]] + 1 �̷� ���� '���� ����' ��� ������ �ϳ� �� �θ� �˴ϴ�.
    // => �׸��� �Ÿ� ����� depthArr[a] + depthArr[b] - 2*depthArr[LCA(a,b)] �� �ϸ� �˴ϴ�.
    //
    // -- ���� --
    //   (1) LCA�� ���ϱ� ���ؼ� "Ʈ�� ����(���� �� ����)"�� �����ؾ� ��. (level[])
    //   (2) depthArr[] = "��Ʈ���� �Ÿ�(����ġ ��)"�� ���� �ΰ�, �Ÿ��� ���߿� ����� ���� ���.
    //   (3) parentArr[v][k] = v�� 2^k��° ����(���� ���� k�� �ö�).
    //
    // �Ʒ������� level[]�� ���� �ξ� ó���ϰڽ��ϴ�.

    // �켱 ���� �ڵ带 ������ �����ؼ� level[] ������� LCA�� ���ϴ� ������ �ٽ� ¥�ڽ��ϴ�.
    // (depthArr�� �Ÿ� �������θ� ���)

    return -1; // �ϴ� �Լ� ��ü�� �ؿ��� �ٽ� �����ϹǷ� ���⼱ �ӽ� ����
}

// (����) ����(���� �� ����)�� ����ġ ��� depth(�Ÿ�) �� �� ����
int levelArr[MAXN + 2];

// level�� �����ִ� �Լ�
int LCA(int a, int b) {
    // 1) ������ �ٸ��� ���� ����÷��� ����
    if (levelArr[a] < levelArr[b])
    {
        swap(a, b);
    }

    int diff = levelArr[a] - levelArr[b];

    for (int i = 0; i < LOGN; i++) 
    {
        if (diff & (1 << i)) 
        {
            a = parentArr[a][i];
        }
    }

    if (a == b)
    {
        return a;
    }

    // 2) ���� ���� ��, ���������� �������� ���� ������ ã�´�
    for (int i = LOGN - 1; i >= 0; i--) 
    {
        if (parentArr[a][i] != parentArr[b][i]) 
        {
            a = parentArr[a][i];
            b = parentArr[b][i];
        }
    }
    // 3) �ٷ� ���� LCA
    return parentArr[a][0];
}

// �� ��� �Ÿ� ���
long long getDist(int a, int b) 
{
    int c = LCA(a, b);

    return depthArr[a] + depthArr[b] - 2LL * depthArr[c];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> Q;
    // �ʱ� ����: ��� 1�� (����ȣ 1)
    // 1�� ����� ����, �Ÿ�(depth)�� 0����
    levelArr[1] = 0;
    depthArr[1] = 0;

    for (int k = 0; k < LOGN; k++) 
    {
        parentArr[1][k] = 1;  // ���ǻ� �ڱ� �ڽ� ����Ű��
    }

    // ������ �� ����. (�ʱ⿣ ��尡 1�����̹Ƿ� L=R=1, ����=0)
    int L = 1, R = 1;
    long long diameter = 0LL;

    // �� ������ ó���ϸ鼭 ��带 �ϳ��� �߰�
    for (int i = 1; i <= Q; i++) 
    {
        int p;         // ������ �θ� ��� q_i
        long long w;   // ���� ����ġ w_i
        cin >> p >> w;

        int newNode = i + 1;  // �̹��� ���� �߰��Ǵ� ��� ��ȣ
        // newNode�� 1�ܰ� ���� ����
        parentArr[newNode][0] = p;
        // ���� = �θ� ���� + 1(���� �ϳ� ����)
        levelArr[newNode] = levelArr[p] + 1;
        // ��Ʈ(1)~newNode������ ����ġ ����
        depthArr[newNode] = depthArr[p] + w;

        // LCA ���̺� ����
        for (int k = 1; k < LOGN; k++)
        {
            parentArr[newNode][k] = parentArr[parentArr[newNode][k - 1]][k - 1];
        }

        // ���� ���� �ĺ� ���
        long long dLR = getDist(L, R);
        long long dLX = getDist(L, newNode);
        long long dRX = getDist(R, newNode);

        // �� ���� �ĺ�
        long long newDiameter = dLR;  // �ϴ� ���� ����
        // ���� dLX�� �� ũ�� ����
        if (dLX > newDiameter)
        {
            newDiameter = dLX;
        }
        // dRX�� �� ũ�� ����
        if (dRX > newDiameter)
        {
            newDiameter = dRX;
        }

        // ���� ������ �ִٸ�, � �Ÿ��� ���ŵƴ��� ���� L,R ��ü
        // (���� �ִ밪�� ���� ������ �ƹ��ų� ���ص� ����)
        if (newDiameter == dLX && newDiameter > dLR) 
        {
            // (L, newNode)�� �� ����
            R = newNode;
        }
        else if (newDiameter == dRX && newDiameter > dLR) 
        {
            // (R, newNode)�� �� ����
            L = newNode;
        }

        diameter = newDiameter;

        // ���
        cout << diameter << "\n";
    }

    return 0;
}
