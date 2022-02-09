#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define endl "\n"
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define trace(x) cerr << #x << " = " << x << '\n'
using namespace std;
const double EPS = 1e-9;
const int INF = 2e9, MOD = 1e9 + 7;

int pow(int a, int b, int m) {int ans = 1; while (b) {if (b & 1) {ans = (ans * a) % m;} b /= 2; a = (a * a) % m; } return ans;}

int32_t main()
{
    IOS;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n, vector<int>(n, INF));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edge[u][v] = min(edge[u][v], w);
        edge[v][u] = min(edge[v][u], w);
    }
    int mx = (1 << n);
    vector<vector<int>> dp(n, vector<int>(mx, INF));
    for (int i = 0; i < n; i++) dp[i][1 << i] = 0;
    for (int mask = 0; mask < mx; mask++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((mask & (1 << j)) && dp[j][mask] < INF)
            {
                for (int i = 0; i < n; i++)
                {
                    if ((i != j) && (edge[j][i] != INF) && ((mask & (1 << i)) == 0))
                    {
                        dp[i][mask | (1 << i)] = min(dp[i][mask | (1 << i)], dp[j][mask] + edge[i][j]);

                    }
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        ans = min(dp[i][mx - 1], ans);
    }
    cout << ans << endl;
    return 0;
}


// micro and graph hackerearth dp with bitmask