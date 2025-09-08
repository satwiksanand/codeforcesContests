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
        int k, x;
        cin >> k >> x;
        int a = x, b = (1LL << (k + 1)) - x;
        vector<int> res;
        while (a != (1LL << k))
        {
            if (a < b)
            {
                b -= a;
                a *= 2;
                res.push_back(1);
            }
            else
            {
                a -= b;
                b *= 2;
                res.push_back(2);
            }
        }
        cout << res.size() << "\n";
        reverse(res.begin(), res.end());
        for (int val : res)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}