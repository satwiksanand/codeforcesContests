#include <bits/stdc++.h>
using namespace std;
#define int long long

int ask(int type, int left, int right)
{
    cout << type << " " << left << " " << right << endl;
    int res;
    cin >> res;
    if (res == -1)
    {
        exit(0);
    }
    return res;
}

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
        int temp1 = ask(2, 1, n);
        int temp2 = ask(1, 1, n);
        int len = temp1 - temp2;
        vector<int> res;
        function<bool(int, int)> solve = [&](int left, int right) -> bool
        {
            if (left > right)
            {
                return false;
            }
            int mid = left + (right - left) / 2;
            int loworg = ask(1, left, mid);
            int lowfake = ask(2, left, mid);
            if (lowfake - loworg == len)
            {
                if (mid - left + 1 == len)
                {
                    res.push_back(left);
                    res.push_back(mid);
                    return true;
                }
                return solve(left, mid);
            }
            else if (lowfake == loworg)
            {
                if (right - mid == len)
                {
                    res.push_back(mid + 1);
                    res.push_back(right);
                    return true;
                }
                return solve(mid + 1, right);
            }
            else
            {
                int curr = lowfake - loworg;
                res.push_back(mid - curr + 1);
                res.push_back(mid + (len - curr));
                return true;
            }
        };
        solve(1, n);
        cout << "! " << res[0] << " " << res[1] << endl;
    }
    return 0;
}