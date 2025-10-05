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
        // cout << "new\n";
        int h, d;
        cin >> h >> d;
        int curr = 0;
        int res = 0LL;
        while (curr < d)
        {
            int low = 1, high = 1e9;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (((mid * (mid + 1)) / 2) < h)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            cout << high << " hello\n";
            if (curr + high >= d)
            {
                res += d - curr;
                break;
            }
            h -= (high * (high + 1) / 2);
            h += 1;
            curr += high;
            res += high;
            res += 1;
            if (high == 1)
            {
                res += (d - curr) * 2 - 1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}