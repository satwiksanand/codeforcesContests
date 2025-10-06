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
        if (k == n * n - 1)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (k > 0)
                {
                    cout << "U";
                }
                else
                {
                    if (k == 0)
                    {
                        if (j == n - 1)
                        {
                            cout << "D";
                        }
                        else
                        {
                            cout << "R";
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            cout << "R";
                        }
                        else
                        {
                            cout << "L";
                        }
                    }
                }
                k -= 1;
            }
            cout << "\n";
        }
    }
    return 0;
}