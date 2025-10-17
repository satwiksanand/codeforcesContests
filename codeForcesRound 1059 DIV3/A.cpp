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
        int val = 0, res = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> val;
            res = max(res, val);
        }
        cout << res << "\n";
    }
    return 0;
}