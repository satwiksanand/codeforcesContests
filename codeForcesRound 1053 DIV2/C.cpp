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
        int tot = 2 * n;
        vector<int> arr(tot + 1);
        for (int i = 1; i <= tot; ++i)
        {
            cin >> arr[i];
        }
        vector<int> res(n + 1);
        for (int k = 1; k <= n; ++k)
        {
            int ind = 1;
            int ans = 0LL;
            while (ind <= tot)
            {
                int left = ind, right = min(ind + 2 * k - 1, tot);
                while (left < right)
                {
                    ans += arr[right] - arr[left];
                    left += 1;
                    right -= 1;
                }
                ind += 2 * k;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}