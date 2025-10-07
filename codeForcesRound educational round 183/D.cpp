#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // didn't submit it, this is using matrix multiplication.

    int tt = 0;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;

        int tot = n * (n - 1) / 2;
        int tar = tot - k;

        vector<vector<int>> dp(n + 1, vector<int>(tot + 1, -1));
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= tot; j++)
            {
                for (int k = 1; k <= i; k++)
                {
                    int temp = k * (k - 1) / 2;
                    if (j >= temp && dp[i - k][j - temp] != -1)
                    {
                        dp[i][j] = k;
                        break;
                    }
                }
            }
        }

        if (dp[n][tar] == -1)
        {
            cout << "0\n";
            continue;
        }

        vector<int> temp2;
        int ind = n, lol = tar;
        while (ind > 0)
        {
            int val = dp[ind][lol];
            temp2.push_back(val);
            lol -= val * (val - 1) / 2;
            ind -= val;
        }

        reverse(temp2.begin(), temp2.end());

        vector<int> res;
        int curr = n;
        for (int val : temp2)
        {
            vector<int> which;
            for (int i = curr - val + 1; i <= curr; ++i)
            {
                which.push_back(i);
            }
            curr -= val;
            for (int x : which)
            {
                res.push_back(x);
            }
        }

        for (int val : res)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
