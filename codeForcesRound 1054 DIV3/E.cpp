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
        // cout << "new\n";
        int n = 0, k, l, r;
        cin >> n >> k >> l >> r;
        int left = 1, a = 1, b = 1;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        map<int, int> mapk, mapkone;
        int res = 0LL;
        for (int i = 1; i <= n; ++i)
        {
            while (a <= n && mapk.size() < k)
            {
                mapk[arr[a]] += 1;
                a += 1;
                if (mapk.size() == k)
                {
                    break;
                }
            }
            while (b <= n)
            {
                if (mapkone.find(arr[b]) != mapkone.end())
                {
                    mapkone[arr[b]] += 1;
                    b += 1;
                }
                else if (mapkone.size() < k)
                {
                    mapkone[arr[b]] += 1;
                    b += 1;
                }
                else
                {
                    break;
                }
            }
            if (mapk.size() < k)
            {
                break;
            }
            // cout << i << " " << a << " " << b << "\n";
            int bind = min(b - 1, n);
            int aind = min(a - 1, n);
            int minsize = aind - i + 1;
            int maxsize = bind - i + 1;
            minsize = max(minsize, l);
            maxsize = min(maxsize, r);
            if (maxsize >= minsize)
            {
                res += maxsize - minsize + 1;
            }
            mapk[arr[i]] -= 1;
            if (mapk[arr[i]] == 0)
            {
                mapk.erase(arr[i]);
            }
            mapkone[arr[i]] -= 1;
            if (mapkone[arr[i]] == 0)
            {
                mapkone.erase(arr[i]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}