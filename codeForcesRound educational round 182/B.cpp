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
        vector<int> mis(n + 1, 1);
        int cnt = 0LL;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            cnt += arr[i] == 0;
            mis[arr[i]] = 0;
        }
        int left = 1, right = n;
        while (left <= n)
        {
            if (arr[left] != left)
            {
                break;
            }
            left += 1;
        }
        while (right >= 1)
        {
            if (arr[right] != right)
            {
                break;
            }
            right -= 1;
        }
        if (left < right)
        {
            if (cnt > 1)
            {
                cout << (right - left + 1) << "\n";
            }
            else if (cnt == 1)
            {
                int which = -1;
                for (int i = 1; i <= n; ++i)
                {
                    if (mis[i] == 1)
                    {
                        which = i;
                        break;
                    }
                }
                if (arr[left] == 0 && left == which)
                {
                    left += 1;
                }
                else if (arr[right] == 0 && right == which)
                {
                    right -= 1;
                }
                while (left <= n)
                {
                    if (arr[left] != left)
                    {
                        break;
                    }
                    left += 1;
                }
                while (right >= 1)
                {
                    if (arr[right] != right)
                    {
                        break;
                    }
                    right -= 1;
                }
                if (left < right)
                {
                    cout << (right - left + 1) << "\n";
                }
                else
                {
                    cout << 0 << "\n";
                }
            }
            else
            {
                cout << (right - left + 1) << "\n";
            }
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    return 0;
}