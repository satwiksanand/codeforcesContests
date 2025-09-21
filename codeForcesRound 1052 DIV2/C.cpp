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
        vector<int> res(n + 1);
        bool ok = true;
        int cnt = 0;
        for (char ch : s)
        {
            if (ch == '0')
            {
                cnt += 1;
            }
            else
            {
                if (cnt == 0 || cnt >= 2)
                {
                    cnt = 0;
                }
                else
                {
                    ok = false;
                }
            }
        }
        if (cnt == 1)
        {
            ok = false;
        }
        if (!ok)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        iota(res.begin(), res.end(), 0);
        int left = 1, right = 1;
        while (right <= n)
        {
            if (s[right - 1] == '1')
            {
                right += 1;
                continue;
            }
            left = right;
            while (right <= n && s[right - 1] != '1')
            {
                right += 1;
            }
            int nextind = right;
            right -= 1;
            while (left <= right)
            {
                swap(res[left], res[right]);
                left += 1;
                right -= 1;
            }
            right = nextind;
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << res[i] << " \n"[i == n];
        }
    }
    return 0;
}