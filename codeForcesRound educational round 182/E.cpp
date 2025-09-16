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
        int val = 0LL;
        int curr = 0LL;
        for (int i = 1; i <= n; ++i)
        {
            cin >> curr;
            val = __gcd(val, curr);
        }
        cout << val << "\n";
    }
    return 0;
}