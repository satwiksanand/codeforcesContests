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
        vector<int> arr(n + 1), pre(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            pre[i] = pre[i - 1] + arr[i];
        }
        array<int, 2> ans = {0, 0};
        bool found = false;
        for (int left = 1; left <= n - 2; ++left)
        {
            for (int right = left + 1; right <= n - 1; ++right)
            {
                int a = pre[left] - pre[0];
                int b = pre[right] - pre[left];
                int c = pre[n] - pre[right];
                a %= 3;
                b %= 3;
                c %= 3;
                if ((a == b && b == c && a == c) || (a != b && b != c && a != c))
                {
                    ans[0] = left;
                    ans[1] = right;
                    found = true;
                }
                if (found)
                {
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}