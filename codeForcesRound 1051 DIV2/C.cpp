#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n = 0;
        cin >> n;
        int u, v, x, y;
        vector<vector<int>> lis(n + 1);
        vector<int> ind(n + 1);
        for (int i = 1; i < n; ++i)
        {
            cin >> u >> v >> x >> y;
            if (u > v)
            {
                swap(u, v);
            }
            if (x > y)
            {
                lis[v].push_back(u);
                ind[u] += 1;
            }
            else
            {
                lis[u].push_back(v);
                ind[v] += 1;
            }
        }
        vector<int> vis(n + 1, 0);
        vector<int> res(n + 1);
        queue<int> qt;
        for (int i = 1; i <= n; ++i)
        {
            if (ind[i] == 0)
            {
                qt.push(i);
            }
        }
        int val = 1;
        while (!qt.empty())
        {
            int size = qt.size();
            for (int i = 1; i <= size; ++i)
            {
                int curr = qt.front();
                qt.pop();
                res[curr] = val;
                val += 1;
                for (int child : lis[curr])
                {
                    ind[child] -= 1;
                    if (ind[child] == 0)
                    {
                        qt.push(child);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << res[i] << " \n"[i == n];
        }
    }
    return 0;
}