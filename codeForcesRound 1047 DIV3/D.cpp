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
        map<int, int> fr;
        map<int, vector<int>> ind;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            fr[arr[i]] += 1;
            ind[arr[i]].push_back(i);
        }
        bool ok = true;
        for (auto it : fr)
        {
            if (it.second % it.first != 0)
            {
                ok = false;
            }
        }
        if (!ok)
        {
            cout << -1 << "\n";
            continue;
        }
        vector<int> res(n + 1);
        int num = 1;
        for (auto it : fr)
        {
            int tot = it.first;
            int cnt = 0;
            for (int curr : ind[it.first])
            {
                if (cnt == tot)
                {
                    cnt = 0;
                    num += 1;
                }
                res[curr] = num;
                cnt += 1;
            }
            num += 1;
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << res[i] << " \n"[i == n];
        }
    }
    return 0;
}