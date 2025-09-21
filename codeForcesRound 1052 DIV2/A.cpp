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
        map<int, int> mt;
        vector<int> arr;
        int val = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> val;
            mt[val] += 1;
        }
        for (auto it : mt)
        {
            arr.push_back(it.second);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        int size = arr.size();
        for (int i = 0; i < (int)arr.size(); ++i)
        {
            ans = max(ans, (size - i) * arr[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}