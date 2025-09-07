#include <bits/stdc++.h>
using namespace std;
#define int long long

int findfact(int a)
{
    if (a % 2 == 0)
    {
        return 2;
    }
    for (int i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
        {
            return i;
        }
    }
    return a;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if (a % 2 == 1 && b % 2 == 1)
        {
            // int sm = findfact(b);
            // cout << "sm: " << sm << "\n";
            ans = max(a + b, a * b + 1);
        }
        else if (a % 2 == 0 && b % 2 == 0)
        {
            ans = max(a + b, a * (b / 2) + 2);
        }
        else if (a % 2 == 0)
        {
            ans = -1;
        }
        else
        {
            int sm = 2;
            if ((b % 4) != 0)
            {
                ans = -1;
            }
            else
            {
                ans = max(a * 2 + b / 2, a * (b / 2) + 2);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}