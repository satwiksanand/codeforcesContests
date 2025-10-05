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
        string s;
        cin >> s;
        vector<int> arr(m + 1);
        for (int i = 1; i <= m; ++i)
        {
            cin >> arr[i];
        }
        int curr = 1;
        set<int> res(arr.begin() + 1, arr.end());

        function<void()> findNextWhiteCell = [&]() -> void
        {
            int ind = lower_bound(arr.begin() + 1, arr.end(), curr) - arr.begin();
            while (ind <= m && arr[ind] == curr)
            {
                curr += 1;
                ind += 1;
            }
        };

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'A')
            {
                curr += 1;
                res.insert(curr);
            }
            else
            {
                curr += 1;
                findNextWhiteCell();
                res.insert(curr);
                curr += 1;
                findNextWhiteCell();
            }
        }
        cout << res.size() << "\n";
        for (int val : res)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}