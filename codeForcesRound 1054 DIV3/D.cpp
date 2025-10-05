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
        vector<int> isl;
        int cnt = 0;
        char pr = s[0];
        for (char ch : s)
        {
            if (ch == pr)
            {
                cnt += 1;
            }
            else
            {
                isl.push_back(cnt);
                pr = ch;
                cnt = 1;
            }
        }
        isl.push_back(cnt);
        int size = isl.size();
        vector<int> pre(size);
        vector<int> suf(size);
        vector<int> sump(size), sumf(size);
        // sump[0] = isl[0];
        for (int i = 0; i < size; ++i)
        {
            sump[i] = isl[i];
            if (i - 2 >= 0)
            {
                sump[i] += sump[i - 2];
            }
        }
        for (int i = size - 1; i >= 0; --i)
        {
            sumf[i] = isl[i];
            if (i + 2 < size)
            {
                sumf[i] += sumf[i + 2];
            }
        }
        for (int i = 2; i < size; ++i)
        {
            pre[i] += pre[i - 2] + sump[i - 2] * isl[i - 1];
        }
        for (int i = size - 3; i >= 0; --i)
        {
            suf[i] += suf[i + 2] + sumf[i + 2] * isl[i + 1];
        }
        int res = 1e16;
        for (int i = 0; i < size; ++i)
        {
            res = min(res, pre[i] + suf[i]);
        }
        cout << res << "\n";
    }
    return 0;
}