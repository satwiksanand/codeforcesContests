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
        vector<int> odd, even;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                even.push_back(arr[i]);
            }
            else
            {
                odd.push_back(arr[i]);
            }
        }
        if (!odd.empty() && !even.empty())
        {
            sort(arr.begin() + 1, arr.end());
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << arr[i] << " \n"[i == n];
        }
    }
    return 0;
}