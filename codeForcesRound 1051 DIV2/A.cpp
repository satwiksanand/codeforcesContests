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
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        int left = 1, right = n;
        int curr = 1;
        bool ok = true;
        while (left <= right)
        {
            if (arr[left] != curr && arr[right] != curr)
            {
                ok = false;
                break;
            }
            if (arr[left] == curr)
            {
                left += 1;
            }
            else if (arr[right] == curr)
            {
                right -= 1;
            }
            curr += 1;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}