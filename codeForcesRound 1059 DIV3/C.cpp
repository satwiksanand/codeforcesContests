#include <bits/stdc++.h>
using namespace std;
// #define int long long

int highestBit(int num)
{
    return 31 - __builtin_clz(num);
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
        if (highestBit(b) > highestBit(a))
        {
            cout << -1 << "\n";
            continue;
        }
        int high = highestBit(a);
        vector<int> res;
        for (int i = 0; i <= high; ++i)
        {
            int mask = 1 << i;
            if ((b & mask) != 0)
            {
                if ((a & mask) != 0)
                {
                    res.push_back(0);
                }
                else
                {
                    res.push_back(mask);
                }
            }
            else
            {
                if ((a & mask) != 0)
                {
                    res.push_back(mask);
                }
                else
                {
                    res.push_back(0);
                }
            }
        }
        cout << (int)res.size() << "\n";
        for (int val : res)
        {
            cout << val << " ";
        }
        cout << "\n";
        // for (int val : res)
        // {
        //     a = a ^ val;
        // }
        // cout << (a == b ? "YES\n" : "NO\n");
    }
    return 0;
}