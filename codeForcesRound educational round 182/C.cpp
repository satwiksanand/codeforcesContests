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
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        int mod = 998244353;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0LL));
        dp[1][0] = 1LL;
        dp[1][1] = 1LL;

        function<bool(array<int, 2> &, array<int, 2> &)> check = [&](array<int, 2> &arr, array<int, 2> &brr) -> bool
        {
            return arr[0] >= brr[0] && arr[1] >= brr[1];
        };

        for (int i = 2; i <= n; ++i)
        {
            array<int, 2> curr0 = {a[i], b[i]};
            array<int, 2> curr1 = {b[i], a[i]};
            array<int, 2> pre0 = {a[i - 1], b[i - 1]};
            array<int, 2> pre1 = {b[i - 1], a[i - 1]};
            if (check(curr0, pre0))
            {
                dp[i][0] += dp[i - 1][0];
            }
            if (check(curr0, pre1))
            {
                dp[i][0] += dp[i - 1][1];
            }
            if (check(curr1, pre0))
            {
                dp[i][1] += dp[i - 1][0];
            }
            if (check(curr1, pre1))
            {
                dp[i][1] += dp[i - 1][1];
            }
            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
        cout << ((dp[n][0] + dp[n][1]) % mod) << "\n";
    }
    return 0;
}