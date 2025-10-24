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
        sort(arr.begin() + 1, arr.end());
        int res = 1LL;
        for (int i = n; i >= 1; --i)
        {
            int val = i;
            int tot = 0LL;
            int which = lower_bound(arr.begin(), arr.end(), val * 4) - arr.begin();
            tot += n + 1 - which;
            for (int j = 1; j <= 3; ++j)
            {
                if (val * j <= n)
                {
                    tot += fr[val * j];
                }
            }
            if (n - tot <= k)
            {
                res = val;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}