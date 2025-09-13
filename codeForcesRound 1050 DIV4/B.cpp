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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int val = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> val;
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> val;
        }
        cout << (n + m) << "\n";
    }
    return 0;
}