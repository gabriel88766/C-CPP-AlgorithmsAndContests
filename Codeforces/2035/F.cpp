#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 2005;   
int v[N];
ll eli[N];
basic_string<int> adj[N];

ll x1, x2;
void dfs(int u, int p){
    ll tt = x1 + (x2 >= u ? 1 : 0);
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            eli[u] += eli[v];
        }
    }
    if(tt >= eli[u]){
        if((tt % 2) == (eli[u] % 2)) eli[u] = 0;
        else eli[u] = 1;
    }else{
        eli[u] -= tt;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        ll s = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            s ^= (v[i] & 1);
        }
        for(int i=1;i<n;i++){
            ll a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        ll ans = INF_LL;
        auto check = [&](ll a, ll b){ // This need to be O(n)
            x1 = a;
            x2 = b;
            for(int i=1;i<=n;i++) eli[i] = v[i];
            dfs(x, 0);
            if(eli[x] == 0) return true;
            else return false;
        };
        for(int r=0;r<n;r++){ //2000^2 * log(2000). Try check in O(N)
            ll cur1 = INF_LL, cur2 = INF_LL;
            //x % 2 == 0
            if((r % 2) == s){
                ll lo = 0, hi = 1e9;
                while(lo != hi){
                    ll mid = lo + (hi - lo) / 2;
                    ll x = 2*mid; //2*mid + 1 if x odd
                    if(check(x, r)) hi = mid;
                    else lo = mid + 1;
                }
                if(check(2*lo, r)) cur1 = (2*lo)*n + r;
            }
            //x % 2 == 1
            if((n + r) % 2 == s){
                ll lo = 0, hi = 1e9;
                while(lo != hi){
                    ll mid = lo + (hi - lo) / 2;
                    ll x = 2*mid + 1; //2*mid + 1 if x odd
                    if(check(x, r)) hi = mid;
                    else lo = mid + 1;
                }
                if(check(2*lo + 1, r)) cur2 = (2*lo + 1)*n + r;
            }
            ans = min(ans, cur1);
            ans = min(ans, cur2);
        }
        for(int i=1;i<=n;i++) adj[i].clear();
        if(ans == INF_LL) cout << "-1\n";
        else cout << ans << "\n";
    }
}
