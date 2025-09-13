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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n + 1);
        vector<int> fr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            fr[arr[i]] += 1;
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i)
        {
            if (fr[i] != 0 && fr[i] % k != 0)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            cout << 0 << "\n";
            continue;
        }
        vector<int> ind(n + 1);
        vector<set<int>> all(n + 1);
        int ans = 0LL;
        int minval = INT_MAX;
        for (int i = n; i >= 1; --i)
        {
            int cnt = fr[arr[i]];
            int need = cnt / k;
            all[arr[i]].insert(i);
            if (all[arr[i]].size() > need)
            {
                int which = *all[arr[i]].rbegin();
                minval = min(minval, which);
                all[arr[i]].erase(which);
            }
            ind[i] = minval;
            if (ind[i] != INT_MAX)
            {
                ans += ind[i] - i;
            }
            else
            {
                ans += n - i + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}