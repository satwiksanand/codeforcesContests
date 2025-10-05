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
        int neg = 0, zero = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            neg += (arr[i] == -1);
            zero += (arr[i] == 0);
        }
        // cout << neg << " " << zero << "\n";
        int res = zero;
        res += (neg % 2) * 2;
        cout << res << "\n";
    }
    return 0;
}