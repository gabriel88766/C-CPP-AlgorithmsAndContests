#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> adj[N];
vector<ll> adjw[N];
ll auxd[N];

ll solve(int u, int p = -1){
    ll ans = 0;
    vector<ll> ad;
    for(int i=0;i<adj[u].size();i++){
        auto v = adj[u][i];
        auto w = adjw[u][i];
        if(v != p){
            ans = max(ans, solve(v, u));
            ad.push_back(auxd[v] + w);
        }
    }
    if(ad.size() == 1){
        ans = max(ans, ad[0]);
        auxd[u] = ad[0];
    }else if(ad.size() >= 2){
        sort(ad.begin(), ad.end(), greater<ll>());
        ans = max(ans, ad[0] + ad[1]);
        auxd[u] = ad[0];
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll ans = 0;
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        ans += c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        adjw[a].push_back(c);
        adjw[b].push_back(c);
    }
    ans *= 2;
    ans -= solve(1);
    cout << ans << "\n";
}
