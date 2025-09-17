#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    int mod = 1e9 + 7;
    cin >> tt;
    while (tt--)
    {
        int n = 0;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(n + 2, vector<int>(n + 2, 0)));
        for (int i = 0; i <= n + 1; ++i)
        {
            for (int j = 0; j <= n + 1; ++j)
            {
                dp[n + 1][i][j] = 1;
            }
        }
        // function<int(int, int, int)> solve = [&](int ind, int mx, int mp) -> int
        // {
        //     if (ind > n)
        //     {
        //         return 1;
        //     }
        //     if (dp[ind][mx][mp] != -1)
        //     {
        //         return dp[ind][mx][mp];
        //     }
        //     int ans = 0LL;
        //     ans += solve(ind + 1, mx, mp);
        //     if (arr[ind] >= mx)
        //     {
        //         ans += solve(ind + 1, arr[ind], mp);
        //     }
        //     else if (arr[ind] >= mp)
        //     {
        //         ans += solve(ind + 1, mx, arr[ind]);
        //     }
        //     ans %= mod;
        //     return dp[ind][mx][mp] = ans;
        // };
        // int res = solve(1, 0, 0);
        for (int ind = n; ind >= 1; --ind)
        {
            for (int mx = 0; mx <= n + 1; ++mx)
            {
                for (int mp = 0; mp <= n + 1; ++mp)
                {
                    dp[ind][mx][mp] += dp[ind + 1][mx][mp];
                    if (arr[ind] >= mx)
                    {
                        dp[ind][mx][mp] += dp[ind + 1][arr[ind]][mp];
                    }
                    else if (arr[ind] >= mp)
                    {
                        dp[ind][mx][mp] += dp[ind + 1][mx][arr[ind]];
                    }
                    dp[ind][mx][mp] %= mod;
                }
            }
        }
        cout << dp[1][0][0] << "\n";
    }
    return 0;
}