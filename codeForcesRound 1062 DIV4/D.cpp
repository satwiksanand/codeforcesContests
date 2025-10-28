#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 200000;

vector<bool> is_prime(MAXN + 1, true);
vector<int> primes;

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAXN; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sieve();
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        int res = -1;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 1)
            {
                res = 2;
            }
        }

        if (res == 2)
        {
            cout << res << "\n";
            continue;
        }
        // cout << primes.size() << "\n";//you are never going that far lol;

        res = 1e15;
        for (int i = 1; i <= n; ++i)
        {
            for (int val : primes)
            {
                if (arr[i] % val != 0)
                {
                    res = min(res, val);
                    break;
                }
            }
        }

        cout << res << "\n";
    }
}
