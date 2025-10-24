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
        if (n % 2 == 0)
        {
            cout << (n - 2) / 2 << "\n";
        }
        else
        {
            cout << (((n - 3) / 2) + 1) << "\n";
        }
    }
    return 0;
}