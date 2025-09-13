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
        int n, m;
        cin >> n >> m;
        vector<array<int, 2>> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i][0] >> arr[i][1];
        }
        int curr = 0;
        int pre = 0;
        int tot = 0LL;
        for (int i = 1; i <= n; ++i)
        {
            int diff = arr[i][0] - pre;
            if (curr == arr[i][1])
            {
                tot += (diff % 2 == 0 ? diff : diff - 1);
            }
            else
            {
                tot += (diff % 2 == 0 ? diff - 1 : diff);
            }
            pre = arr[i][0];
            curr = arr[i][1];
        }
        if (pre != m)
        {
            tot += m - pre;
        }
        cout << tot << "\n";
    }
    return 0;
}