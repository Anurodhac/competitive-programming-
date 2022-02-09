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
int n;
const int N = 19;
int mx = (1ll << 19);
vector<vector<double>> a(N, vector<double>(N));
vector<double> dp(mx);

double recurse(int mask)
{
    int one = __builtin_popcount(mask);
    if (one == n) return double(1);

    if (dp[mask] != 0) return dp[mask];

    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i) continue;
                if ((mask & (1 << j)) == 0)
                {
                    double cur = 2 / ((double)(one) * (one + 1));
                    dp[mask] += recurse(mask | (1 << j)) * (cur * a[i][j]);
                }
            }
        }
    }
    return dp[mask];

}



int32_t main()
{
    IOS;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    for (int j = 0; j < (1 << n); j++) dp[j] = 0;
    vector<double> ans(n, 0);
    for (int i = 0; i < n; i++) cout << fixed << setprecision(9) << recurse(1 << i) << " ";
    cout << endl;

    return 0;
}