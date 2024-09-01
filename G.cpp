#include<bits/stdc++.h>
using namespace std;

#define int long long
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
const int MOD = 1e18 + 7;
const int maxN = 1e6 + 5;

int xA, yA, xB, yB, n, moveX, moveY;
string wind;

bool check(int k) {
    int frq = k / n;
    int mod = k % n;

    int totMoveX = xA + moveX * frq;
    int totMoveY = yA + moveY * frq;

    for (int i=0; i<mod; i++) {
        if (wind[i] == 'U') totMoveY++;
        if (wind[i] == 'D') totMoveY--;
        if (wind[i] == 'R') totMoveX++;
        if (wind[i] == 'L') totMoveX--;
    }

    int neededMoveX = abs(xB - totMoveX);
    int neededMoveY = abs(yB - totMoveY);

    return k >= neededMoveX + neededMoveY;
}

void solve()
{

    cin >> xA >> yA;
    cin >> xB >> yB;

    cin >> n;
    cin >> wind;
    
    moveX = 0;
    moveY = 0;
    for (int i=0; i<n; i++) {
        if (wind[i] == 'U') moveY++;
        if (wind[i] == 'D') moveY--;
        if (wind[i] == 'R') moveX++;
        if (wind[i] == 'L') moveX--;
    }

    int l = 0;
    int r = INF;
    int ans = -1;
    while(l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}