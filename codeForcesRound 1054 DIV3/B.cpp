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
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr.begin() + 1, arr.end());
        int res = -1e9;
        for (int i = 2; i <= n; i += 2)
        {
            res = max(res, arr[i] - arr[i - 1]);
        }
        cout << res << "\n";
    }
    return 0;
}