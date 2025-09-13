#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5;

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
        vector<vector<int>> arr(n + 1);
        vector<int> allSize(n + 1);
        int maxSizeAll = 0;
        int k = 0;
        int minval = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            cin >> k;
            allSize[i] = k;
            maxSizeAll = max(maxSizeAll, k);
            arr[i].resize(k + 1);
            int val = 0;
            for (int j = 1; j <= k; ++j)
            {
                cin >> val;
                arr[i][j] = val;
                if (j == 1)
                {
                    minval = min(minval, val);
                }
            }
        }
        vector<vector<int>> ind(maxSizeAll + 1);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= allSize[i]; ++j)
            {
                ind[j].push_back(i);
            }
        }
        vector<int> ans;
        ans.push_back(minval);
        int minSize = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            if (arr[i][1] == minval)
            {
                minSize = min(minSize, (int)arr[i].size() - 1);
            }
        }
        // cout << "print:->\n";
        // cout << minval << " " << minSize << "\n";
        // int lol = 0LL;
        for (int col = 2; col <= maxSizeAll; ++col)
        {
            // lol += 1;
            int newMinval = INT_MAX;
            int allMin = INT_MAX;
            bool can = minSize < col;
            for (int which : ind[col])
            {
                if (arr[which].size() >= col)
                {
                    allMin = min(allMin, arr[which][col]);
                }
                if (arr[which][col - 1] == minval && arr[which].size() >= col)
                {
                    newMinval = min(newMinval, arr[which][col]);
                }
            }
            if (can)
            {
                minval = allMin;
            }
            else
            {
                minval = newMinval;
            }
            int newMinSize = INT_MAX;
            for (int which : ind[col])
            {
                if (arr[which][col] == minval)
                {
                    newMinSize = min(newMinSize, (int)arr[which].size() - 1);
                }
            }
            minSize = newMinSize;
            ans.push_back(minval);
        }
        // cout << "lol:-> " << lol << "\n";
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}