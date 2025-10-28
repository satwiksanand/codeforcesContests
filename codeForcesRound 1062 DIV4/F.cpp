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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> lis(n + 1);
        int u, v;
        for (int i = 1; i < n; ++i)
        {
            cin >> u >> v;
            lis[u].push_back(v);
            lis[v].push_back(u);
        }
        int res = n * n;
        // map<int, map<int, int>> all; // i need a better way to code this shit up.
        function<int(int, int)> dfs = [&](int node, int parent) -> int
        {
            int ans = 1;
            for (int child : lis[node])
            {
                if (child == parent)
                {
                    continue;
                }
                int curr = dfs(child, node);
                if (n - curr < k)
                {
                    res -= curr;
                }
                // all[node][child] = curr;
                ans += curr;
            }
            if (ans < k)
            {
                res -= n - ans;
            }
            return ans;
        };

        // function<void(int, int)> dfs2 = [&](int node, int parent) -> void{
        //     for(int child : lis[node]){
        //         if(child == parent){
        //             continue;
        //         }

        //     }
        // };
        dfs(1, 0);
        cout << res << "\n";
    }
    return 0;
}