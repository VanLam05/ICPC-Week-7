// công thức dp đúng nhưng sub tràn số
// dùng py đi

#include <bits/stdc++.h>
using namespace std;

#define ll __uint128_t
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

void print(ll value) {
    vector<int> res;
    while (value)
    {
        int tmp = value % 10;
        res.push_back(tmp);
        value /= 10;
    }
    
    for (int i=res.size(); i>0; i--)
        cout << res[i-1];
    cout << '\n';
}

void solve()
{
    int n;
    cin >> n;
    vvl res(n + 1, vl(n + 1, 0));

    res[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            res[i][j] = (ll)res[i - 1][j] * j + res[i - 1][j - 1];
        }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += (ll)res[n][i];
    print(ans);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
