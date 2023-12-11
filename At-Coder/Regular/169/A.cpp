#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 250005;
vector<int> adj[N];
int h[N];
int mh = 0;
void dfs(int u = 1, int p = 0){
    h[u] = h[p] + 1;
    mh = max(mh, h[u]);
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    for(int i=2;i<=n;i++){
        int b;
        cin >> b;
        adj[i].push_back(b);
        adj[b].push_back(i);
    }
    h[0] = -1;
    dfs(1);
    vector<vector<ll>> hs(mh+1);
    for(int i=1;i<=n;i++){
        hs[h[i]].push_back(v[i]);
    }
    for(int i=mh;i>=0;i--){
        ll sum = 0;
        for(auto x : hs[i]) sum += x;
        if(sum > 0){
            cout << "+\n";
            return 0;
        }
        if(sum < 0){
            cout << "-\n";
            return 0;
        }
    }
    cout << "0\n";
}
