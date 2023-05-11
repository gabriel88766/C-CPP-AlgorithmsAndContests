#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int n;
ll ans = 0;



ll calc(int a, int b, int c){
    ll minv = min(a,c);
    ll maxv = max(a,c);
    if(minv > b){
        return (n-maxv+1)*(minv-b);
    }else if(b > maxv){
        return (b-maxv)*minv;
    }else return 0;
}

void dfs(int u, int p = -1){
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            for(auto x : adj[v]){
                if(u != x) ans += calc(u, v, x);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    cin >> n;
    for(int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    ans = ((ll)n * (n+1))/2;
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            for(int k=0;k<adj[i].size();k++){
                if(j != k) ans += calc(adj[i][j], i, adj[i][k]);
            }
        }
    }
    cout << calc(2,7,4) << " " << calc(2,7,5) << " " << calc(4,7,5) << "\n";



    cout << ans;
}
