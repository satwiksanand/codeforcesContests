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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        int rem = k, res = 0LL;
        for (int i = n; i >= 1; --i)
        {
            res += rem * a[i];
            rem -= 1;
            if (rem == 0)
            {
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}