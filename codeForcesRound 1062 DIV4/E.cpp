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
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr.begin() + 1, arr.end());
        vector<int> res(k + 1);
        function<bool(int)> check = [&](int val) -> bool
        {
            int tot = 1;
            // int ind = 1;
            int left = 0;
            int right = arr[1] - val;
            while (tot <= k && left <= right)
            {
                res[tot] = left;
                left += 1;
                tot += 1;
            }
            for (int i = 2; i <= n; ++i)
            {
                left = max(left, arr[i - 1] + val);
                right = arr[i] - val;
                while (tot <= k && left <= right)
                {
                    res[tot] = left;
                    left += 1;
                    tot += 1;
                }
            }
            left = max(left, arr[n] + val);
            right = x;
            while (tot <= k && left <= right)
            {
                res[tot] = left;
                left += 1;
                tot += 1;
            }
            return tot > k;
        };
        int low = 0, high = 1e9;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        // cout << high << "\n";
        check(high);
        for (int i = 1; i <= k; ++i)
        {
            cout << res[i] << " \n"[i == k];
        }
    }
    return 0;
}