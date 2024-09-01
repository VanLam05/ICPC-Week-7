#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int, int>
#define pib pair<int, bool>
#define pdd pair<double, double>
#define mii map<int, int>
#define mib map<int, bool>
#define mil map<int, ll>
#define mli map<ll, int>
#define si set<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define vvb vector<vb>
#define vpi vector<pii>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yn yes else no
#define ny no else yes

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int maxN = 1e6 + 5;

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int &x : a)
        cin >> x;
    sort(all(a));
    mib mp;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[1]) break;
        mp[a[i]] = true;
        if (i != 0 && a[i] == a[i - 1]) {
            continue;
        }
        if (i != n - 1 && a[i] == a[i + 1]) 
            continue;

        bool check = true;
        for (int j = 2; j * j <= a[i]; j++)
            if (a[i] % j == 0)
            {
                if (mp[j] || mp[a[i] / j])
                {
                    check = false;
                    break;
                }
            }
        if (check)
            res++;
    }

    cout << res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}