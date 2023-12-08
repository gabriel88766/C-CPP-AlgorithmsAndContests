#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1000001;
vector<int> adj[N];
int sub[N], par[N];
char bs[N];

void dfs(int u,int p){
    par[u] = p;
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}
ll ans = 0;

const int maxv = 1000001;
map<int,int> mp;

ll subset_sum(ll n){
    memset(bs, 0, (n+1) * sizeof(char));
    bs[0] = 1;
    for(auto [k, v] : mp){
        for(int j=0;j<v;j++){
            for(int i = n; i>= k; i--){
                bs[i] |= bs[i-k];
            }
        }
    }
    ll maxv = 0;
    for(ll i=0;i<=n;i++){ 
        if(bs[i]){  
            maxv = max(maxv, (n - i) * i);
        }
    }
    return maxv;
}


void calc(int u, int p){
    vector<ll> v;
    ll s = 0;
    for(auto x : adj[u]){
        if(x != p){
            v.push_back(sub[x]);
            s += v.back();
        }
    }
    //something bad make it good! magic???
    if(v.size()){
        int x = *max_element(v.begin(), v.end());
        if(s - x <= x){
            ll a1 = x;
            ll a2 = s - x;
            ans += a1*a2;
        }else{
            
            for(int i=0;i<v.size();i++) mp[v[i]]++;
            for(auto [k, v] : mp){
                if(v >= 3){
                    if((v-1)/2) mp[2*k] += (v-1)/2;
                    mp[k] = 1 + (v-1) % 2;
                }
            }
            ans += subset_sum(s);
            mp.clear();
        }
        
        //end
        v.clear();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++){
        calc(i, par[i]);
    }
    cout << ans << "\n";
}
