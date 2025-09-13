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
        vector<int> a(n + 1);
        int ans = 0LL;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ans += i % 2 == 0 ? -a[i] : a[i];
        }
        int init = ans;
        ans += n % 2 == 0 ? n - 2 : n - 1;
        int even = LLONG_MAX / 2, odd = LLONG_MAX / 2;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 2 == 0)
            {
                ans = max(ans, init + i + a[i] + a[i] - even);
                odd = min(odd, i - a[i] - a[i]);
            }
            else
            {
                ans = max(ans, init + i - a[i] - a[i] - odd);
                even = min(even, i + a[i] + a[i]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}