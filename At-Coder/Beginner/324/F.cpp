#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> adj[N], adjb[N], adjv[N];
pair<ll, ll> dp[N];
bool comp(double frac, pair<ll, ll> &u, pair<ll, ll> &v){
    double x1 = frac * u.second - u.first;
    double x2 = frac * v.second - v.first;
    return x1 < x2;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, c, b, v;
        cin >> a >> c >> b >> v;
        adj[a].push_back(c);
        adjb[a].push_back(b);
        adjv[a].push_back(v);
    }
    double lo = 1e-12, hi = 1e12;
    while(hi - lo > EPS){
        double mid = (lo + hi)/2;
        dp[1] = {0LL, 0LL};
        for(int i=2;i<=n;i++) dp[i] = {0, INF_LL};
        for(int i=1;i<=n;i++){
            for(int j=0;j<adj[i].size(); j++){
                pair<ll, ll> nowc =  {dp[i].first + adjb[i][j], adjv[i][j] + dp[i].second};
                if(comp(mid, nowc, dp[adj[i][j]])){
                    dp[adj[i][j]] = nowc;
                }
            }
        }
        double x = dp[n].first;
        x /= dp[n].second;
        if(x > mid) lo = mid;
        else hi = mid;
    }    
    cout << fixed << setprecision(15) << lo << "\n";
}
