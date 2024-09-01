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

vi seg;

void update(int id, int l, int r, int i, int v)
{
    if (i < l || i > r)
        return;
    if (l == r)
    {
        seg[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return INF;
    if (u <= l && r <= v)
        return seg[id];

    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void solve()
{
    int n;
    cin >> n;
    seg.assign(4 * n + 5, 0);

    vi a(n + 1);
    vector<queue<int>> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ind[a[i]].push(i);
        update(1, 1, n, i, a[i]);
    }
    vi b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        // nếu không tồn tại phần tử b[i] trong a
        if (ind[b[i]].empty())
        {
            no return;
        }
        // tìm index j bé nhất mà a[j] = b[i]
        int j = ind[b[i]].front();
        ind[b[i]].pop();

        int tmp = get(1, 1, n, 1, j);
        // nếu tồn tại a[k] sao cho k < j && a[k] < a[j]
        if (tmp != b[i])
        {
            no return;
        }

        update(1, 1, n, j, INF);
    }

    yes return;
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
