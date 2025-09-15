#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = INT_MAX;

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
        vector<int> sizes(n + 1);
        int minval = inf;
        for (int i = 1; i <= n; ++i)
        {
            int k = 0;
            cin >> k;
            sizes[i] = k;
            arr[i].resize(k + 1);
            for (int j = 1; j <= k; ++j)
            {
                cin >> arr[i][j];
                if (j == 1)
                {
                    minval = min(minval, arr[i][j]);
                }
            }
        }
        int maxSize = *max_element(sizes.begin(), sizes.end());
        vector<vector<int>> ind(maxSize + 1);
        set<int> allInd;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= sizes[i]; ++j)
            {
                ind[j].push_back(i);
            }
            if (arr[i][1] == minval)
            {
                allInd.insert(i);
            }
        }
        vector<int> ans;
        ans.push_back(minval);
        for (int col = 2; col <= maxSize; ++col)
        {
            int newMinVal = inf, allMinVal = inf;
            bool can = false;
            for (int which : allInd)
            {
                if (sizes[which] < col)
                {
                    can = true;
                    break;
                }
            }
            if (can)
            {
                for (int which : ind[col])
                {
                    newMinVal = min(newMinVal, arr[which][col]);
                }
                allInd.clear();
                minval = newMinVal;
                for (int which : ind[col])
                {
                    if (arr[which][col] == minval)
                    {
                        allInd.insert(which);
                    }
                }
                ans.push_back(minval);
            }
            else
            {
                vector<int> tempInd;
                for (int which : allInd)
                {
                    newMinVal = min(newMinVal, arr[which][col]);
                    tempInd.push_back(which);
                }
                allInd.clear();
                minval = newMinVal;
                for (int which : tempInd)
                {
                    if (arr[which][col] == minval)
                    {
                        allInd.insert(which);
                    }
                }
                ans.push_back(minval);
            }
        }
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}