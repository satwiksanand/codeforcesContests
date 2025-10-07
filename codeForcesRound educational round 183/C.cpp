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
        string s;
        cin >> s;

        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = s[0] == 'a' ? 1 : -1;
        for (int i = 1; i < n; ++i)
        {
            pre[i] = pre[i - 1] + (s[i] == 'a' ? 1 : -1);
        }
        suf[n - 1] = s[n - 1] == 'a' ? 1 : -1;
        for (int i = n - 2; i >= 0; --i)
        {
            suf[i] = suf[i + 1] + (s[i] == 'a' ? 1 : -1);
        }

        if (pre[n - 1] == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        map<int, set<int>> lol;
        for (int i = 0; i < n; ++i)
        {
            lol[suf[i]].insert(i);
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            lol[suf[i]].erase(i);
            int val = -pre[i];
            if (lol.find(val) != lol.end() && !lol[val].empty())
            {
                res = max(res, n - *lol[val].begin() + i + 1);
            }
            if (pre[n - 1] == pre[i])
            {
                res = max(res, n - (i + 1));
            }
            if (pre[i] == 0)
            {
                res = max(res, i + 1);
            }
        }
        cout << (res == 0 ? -1 : n - res) << "\n";
    }
    return 0;
}