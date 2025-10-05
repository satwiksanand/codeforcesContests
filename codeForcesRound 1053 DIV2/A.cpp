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
        vector<int> arr(m + 1);
        // int maxval = 0;
        bool ok = true;
        for (int i = 1; i <= m; ++i)
        {
            cin >> arr[i];
            if (i != 1)
            {
                ok = arr[i] == arr[i - 1] + 1 ? ok : false;
            }
        }
        cout << (ok ? n - arr[m] + 1 : 1) << "\n";
    }
    return 0;
}