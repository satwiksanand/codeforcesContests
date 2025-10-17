#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(string &s)
{
    if (s.empty())
    {
        return true;
    }
    char ch = s[0];
    for (char val : s)
    {
        if (val == '0' && ch == '1')
        {
            return false;
        }
        ch = val;
    }
    return true;
}

bool isPalin(string &s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
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
        int n = 0;
        cin >> n;
        string s;
        cin >> s;
        int high = (1LL << n);
        int res = -1;
        for (int mask = 0; mask < high; ++mask)
        {
            string first = "", second = "";
            for (int i = 0; i < n; ++i)
            {
                if ((mask & (1LL << i)) != 0)
                {
                    first.push_back(s[i]);
                }
                else
                {
                    second.push_back(s[i]);
                }
            }
            if (check(first) && isPalin(second))
            {
                res = mask;
                break;
            }
        }
        if (res == -1)
        {
            cout << res << "\n";
            continue;
        }
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((res & (1LL << i)) != 0)
            {
                cnt += 1;
                ans.push_back(i + 1);
            }
        }
        // cout << "\n";
        cout << cnt << "\n";
        for (int vla : ans)
        {
            cout << vla << " ";
        }
        cout << "\n";
    }
    return 0;
}