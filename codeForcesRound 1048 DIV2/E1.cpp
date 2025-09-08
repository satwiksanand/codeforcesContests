#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<vector<int>, int> knapsackMaxItemsIter(vector<int> &all, int W)
{
    int n = all.size();

    vector<pair<int, int>> dp(W + 1, {0, 0});
    vector<pair<int, int>> newdp(W + 1);

    vector<int> choice(W + 1, -1);
    vector<int> prevCap(W + 1, -1);
    vector<int> newChoice, newPrevCap;

    for (int i = 0; i < n; i++)
    {
        newdp = dp;
        newChoice = choice;
        newPrevCap = prevCap;

        for (int rem = all[i]; rem <= W; rem++)
        {
            auto res = dp[rem - all[i]];
            res.first += 1;
            res.second += all[i];

            if (res.first > newdp[rem].first ||
                (res.first == newdp[rem].first && res.second > newdp[rem].second))
            {
                newdp[rem] = res;
                newChoice[rem] = i;
                newPrevCap[rem] = rem - all[i];
            }
        }
        dp.swap(newdp);
        choice.swap(newChoice);
        prevCap.swap(newPrevCap);
    }

    int bestRem = 0;
    pair<int, int> ans = {0, 0};
    for (int rem = 0; rem <= W; rem++)
    {
        if (dp[rem].first > ans.first ||
            (dp[rem].first == ans.first && dp[rem].second > ans.second))
        {
            ans = dp[rem];
            bestRem = rem;
        }
    }

    vector<int> picked;
    int cur = bestRem;
    while (cur >= 0 && choice[cur] != -1)
    {
        picked.push_back(choice[cur]);
        cur = prevCap[cur];
    }
    reverse(picked.begin(), picked.end());

    int remaining = W - ans.second;
    return {picked, remaining};
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
        int n = 0, x = 0;
        cin >> n >> x;
        vector<int> par(n + 1);
        for (int i = 2; i <= n; ++i)
        {
            cin >> par[i];
        }
        vector<vector<int>> lis(n + 1);
        for (int i = 2; i <= n; ++i)
        {
            lis[par[i]].push_back(i);
        }
        function<int(int, int, int)> findMinDepth = [&](int node, int parent, int depth) -> int
        {
            if (lis[node].size() == 0)
            {
                return depth;
            }
            int res = INT_MAX;
            for (int child : lis[node])
            {
                if (child == parent)
                {
                    continue;
                }
                res = min(res, findMinDepth(child, node, depth + 1));
            }
            return res;
        };
        int minDepth = findMinDepth(1, -1, 1);
        vector<int> all(minDepth);
        queue<int> qt;
        qt.push(1);
        for (int i = 0; i < minDepth; ++i)
        {
            int size = qt.size();
            all[i] = size;
            while (size--)
            {
                int node = qt.front();
                qt.pop();
                for (int child : lis[node])
                {
                    qt.push(child);
                }
            }
        }
        // cout << "reached here:-> \n";
        // for (int val : all)
        // {
        //     cout << val << " ";
        // }
        // cout << "\n";
        int tot = accumulate(all.begin(), all.end(), 0LL);
        int left = n - tot;
        int val = min(x, n - x);
        pair<vector<int>, int> res = knapsackMaxItemsIter(all, val);
        sort(res.first.begin(), res.first.end());
        // for (int val : res.first)
        // {
        //     cout << val << " ";
        // }
        // cout << "\n";
        // cout << res.second << "\n";
        // cout << "print statement:-> \n";
        // cout << res.second << " " << left << "\n";
        int ans = res.first.size();
        if (res.second <= left)
        {
            ans = minDepth;
        }
        else
        {
            int ind = res.first.size() - 1;
            res.second -= left;
            left = res.second;
            for (int i = minDepth - 1; i >= 0; --i)
            {
                if (ind >= 0 && i == res.first[ind])
                {
                    ind -= 1;
                    continue;
                }
                if (left <= 0)
                {
                    ans += 1;
                }
                else
                {
                    left -= all[i];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}