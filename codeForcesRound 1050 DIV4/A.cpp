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
        int x, n;
        cin >> x >> n;
        cout << (n % 2 == 0 ? 0 : x) << "\n";
    }
    return 0;
}