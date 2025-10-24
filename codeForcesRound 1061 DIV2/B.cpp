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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> all(q + 1);
        for (int i = 1; i <= q; ++i)
        {
            cin >> all[i];
        }
        bool bpre = false;
        for (char ch : s)
        {
            if (ch == 'B')
            {
                bpre = true;
                break;
            }
        }
        for (int i = 1; i <= q; ++i)
        {
            int val = all[i];
            if (!bpre)
            {
                cout << val << "\n";
                continue;
            }
            int res = 0;
            int ind = 0;
            while (val > 0)
            {
                if (s[ind] == 'A')
                {
                    val -= 1;
                }
                else
                {
                    val /= 2;
                }
                ind += 1;
                ind %= n;
                res += 1;
            }
            cout << res << "\n";
        }
    }
    return 0;
}