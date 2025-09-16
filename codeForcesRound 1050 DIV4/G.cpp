#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
    int MXN = 2e5 + 2;
    vector<vector<int>> divs(MXN + 1);
    for (int i = 2; i <= MXN; ++i)
    {
        for (int j = i; j <= MXN; j += i)
        {
            divs[j].push_back(i);
        }
    }
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
        int res = 0LL;
        vector<int> cnt(n + 1), vis(n + 1); // vis kind of makes sure that the number is present in the prev array
        vector<int> prev;
        for (int i = 1; i <= n; ++i)
        {
            int val = arr[i];
            vector<int> next; // this will store the divisors which divide all the elements in the current prefix.
            for (int curr : divs[val])
            {
                cnt[curr] += 1;
                if (cnt[curr] != i)
                {
                    res = max(res, cnt[curr]);
                }
                else if (!vis[curr])
                {
                    vis[curr] = 1;
                    next.push_back(curr);
                }
            }

            for (int curr : prev)
            {
                if (cnt[curr] != i)
                {
                    res = max(res, cnt[curr]);
                    vis[curr] = 0;
                }
                else
                {
                    next.push_back(curr);
                }
            }
            prev = move(next);
            cout << res << " \n"[i == n];
        }
    }
    return 0;
}