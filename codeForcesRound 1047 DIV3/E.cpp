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
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        k = k > 2 ? 2 + (k % 2) : k;
        function<void()> calc = [&]() -> void
        {
            set<int> ind;
            map<int, int> fr;
            for (int i = 1; i <= n; ++i)
            {
                ind.insert(arr[i]);
                fr[arr[i]] += 1;
            }
            int mex = 0;
            for (int val : ind)
            {
                if (val == mex)
                {
                    mex += 1;
                }
                else
                {
                    break;
                }
            }
            for (int i = 1; i <= n; ++i)
            {
                if (arr[i] > mex || fr[arr[i]] != 1)
                {
                    arr[i] = mex;
                }
            }
        };
        for (int i = 1; i <= k; ++i)
        {
            calc();
        }
        cout << (accumulate(arr.begin() + 1, arr.end(), 0LL)) << "\n";
    }
    return 0;
}