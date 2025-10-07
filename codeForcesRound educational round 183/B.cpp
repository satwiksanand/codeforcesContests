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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string res = "";
        for (int i = 0; i < n; ++i)
        {
            res.push_back((k == n ? '-' : '+'));
        }
        if (k == n)
        {
            cout << res << "\n";
            continue;
        }
        int zero = 0, one = 0, rem = 0;
        for (char ch : s)
        {
            if (ch == '0')
            {
                zero += 1;
            }
            else if (ch == '1')
            {
                one += 1;
            }
            else
            {
                rem += 1;
            }
        }
        for (int i = 0; i < zero; ++i)
        {
            res[i] = '-';
        }
        for (int i = n - 1; i >= 0 && i > n - 1 - one; --i)
        {
            res[i] = '-';
        }
        for (int i = zero; i < zero + rem; ++i)
        {
            res[i] = '?';
        }
        for (int i = n - 1 - one; i >= 0 && i > n - 1 - one - rem; --i)
        {
            res[i] = '?';
        }
        cout << res << "\n";
    }
    return 0;
}