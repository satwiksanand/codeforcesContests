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
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        vector<int> all;
        int ans = 0LL;
        for (int i = 1; i <= n; ++i)
        {
            while (!all.empty() && a[i] > a[all.back()])
            {
                all.pop_back();
            }
            int low = 0, high = (int)(all.size()) - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (a[all[mid]] >= max(a[i], b[i]))
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            int ind = high >= 0 ? all[high] : -1;
            ind = a[i] == b[i] ? i : ind;
            all.push_back(i);
            if (ind != -1)
            {
                ans += ind * (n - i + 1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}