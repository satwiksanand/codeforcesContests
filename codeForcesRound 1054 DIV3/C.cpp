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
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> arr(n + 1);
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            cnt[arr[i]] += 1;
        }
        int res = 0;
        int tot = 0;
        for (int i = 0; i < k; ++i)
        {
            tot += cnt[i] == 0;
        }
        res = cnt[k] >= tot ? cnt[k] : tot;
        cout << res << "\n";
    }
    return 0;
}