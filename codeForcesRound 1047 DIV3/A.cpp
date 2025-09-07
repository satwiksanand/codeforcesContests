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
        int n, x;
        cin >> n >> x;
        while (n--)
        {
            x *= 2;
        }
        cout << x << "\n";
    }
    return 0;
}