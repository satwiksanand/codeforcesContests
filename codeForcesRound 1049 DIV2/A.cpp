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
        string s;
        cin >> s;
        string t = s;
        int res = 0LL;
        sort(t.begin(), t.end());
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != t[i])
            {
                res += 1;
            }
        }
        cout << res / 2 << "\n";
    }
    return 0;
}