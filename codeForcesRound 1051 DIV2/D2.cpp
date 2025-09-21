#include <bits/stdc++.h>
using namespace std;

const int NMAX = 3000;
const int modulo = 1e9 + 7;

void addSelf(int &x, int y)
{
    x += y;
    if (x >= modulo)
        x -= modulo;
}

struct SegmentTree
{
    int n;
    vector<int> tree;

    SegmentTree(int n)
    {
        this->n = n;
        tree.assign(4 * n, 0);
    }

    void update(int node, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            tree[node] += val;
            if (tree[node] >= modulo)
                tree[node] -= modulo;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(2 * node, l, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, r, pos, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
        if (tree[node] >= modulo)
            tree[node] -= modulo;
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) >> 1;
        int left = query(2 * node, l, mid, ql, qr);
        int right = query(2 * node + 1, mid + 1, r, ql, qr);
        int ans = left + right;
        if (ans >= modulo)
            ans -= modulo;
        return ans;
    }

    void update(int pos, int val) { update(1, 0, n, pos, val); }
    int query(int pos) { return query(1, 0, n, 0, pos); } // prefix sum
};

int n, a[NMAX + 5], b[NMAX + 5];
SegmentTree *seg_lin[NMAX + 5];
SegmentTree *seg_col[NMAX + 5];

void update_lin(int lin, int pos, int val) { seg_lin[lin]->update(pos, val); }
void update_col(int col, int pos, int val) { seg_col[col]->update(pos, val); }
int query_lin(int lin, int pos) { return seg_lin[lin]->query(pos); }
int query_col(int col, int pos) { return seg_col[col]->query(pos); }

void testcase()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        a[i] = 1;
        for (int j = 1; j < i; j++)
            if (b[j] <= b[i])
                a[i]++;
        for (int j = i + 1; j <= n; j++)
            if (b[j] < b[i])
                a[i]++;
    }
    for (int i = 0; i <= n + 1; i++)
    {
        seg_lin[i] = new SegmentTree(n + 1);
        seg_col[i] = new SegmentTree(n + 1);
    }
    update_lin(0, 0, 1);
    update_col(0, 0, 1);

    for (int i = 1; i <= n; i++)
    {
        vector<pair<int, pair<int, int>>> buffs;
        int x = a[i];
        for (int j = x + 1; j <= n; j++)
        {
            int lin = j, col = x;
            int buff = query_lin(j, x - 1);
            buffs.push_back({buff, {lin, col}});
        }
        for (int q = 0; q < x; q++)
        {
            int lin = x, col = q;
            int buff = query_col(q, x - 1);
            buffs.push_back({buff, {lin, col}});
        }
        for (auto it : buffs)
        {
            update_lin(it.second.first, it.second.second, it.first);
            update_col(it.second.second, it.second.first, it.first);
        }
    }

    int ans = 0;
    for (int lin = 0; lin <= n; lin++)
        addSelf(ans, query_lin(lin, n));
    cout << ans << "\n";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        testcase();
    return 0;
}
