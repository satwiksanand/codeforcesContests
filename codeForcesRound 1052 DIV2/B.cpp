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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ind(m + 1);
        int size = 0;
        int val = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> size;
            for (int j = 1; j <= size; ++j)
            {
                cin >> val;
                ind[val].push_back(i);
            }
        }
        vector<int> cnt(n + 1);
        bool ok = true;
        for (int i = 1; i <= m; ++i)
        {
            if (ind[i].empty())
            {
                ok = false;
                break;
            }
            else if (ind[i].size() == 1)
            {
                cnt[ind[i][0]] = 1;
            }
        }
        int tot = accumulate(cnt.begin() + 1, cnt.end(), 0LL);
        if (tot <= n - 2 && ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}