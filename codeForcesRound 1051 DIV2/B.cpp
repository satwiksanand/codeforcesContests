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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n + 1), b(k + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        for (int i = 1; i <= k; ++i)
        {
            cin >> b[i];
        }
        sort(arr.begin() + 1, arr.end(), greater<int>());
        sort(b.begin() + 1, b.end());
        int right = 1;
        int ind = 1;
        int res = 0LL;
        while (ind <= n)
        {
            if (right <= k && b[right] <= (n - ind + 1))
            {
                int size = b[right];
                for (int i = 1; i <= size; ++i)
                {
                    res += i == size ? 0 : arr[ind];
                    ind += 1;
                }
                right += 1;
            }
            else
            {
                res += arr[ind];
                ind += 1;
            }
        }
        cout << res << "\n";
    }
    return 0;
}