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
        int x;
        cin >> x;
        // string s = to_string(x);
        // s += to_string(x * 2);
        // int val = stoll(s);
        // if (val % 3 * x == 0)
        // {
        //     cout << "yes\n";
        // }
        cout << x * 2 << "\n";
    }
    return 0;
}