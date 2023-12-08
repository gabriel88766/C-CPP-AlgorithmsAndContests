#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5005;
vector<int> adj[N];
int sub[N];

void dfs(int u,int p){
    sub[u] = 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}
ll ans = 0;
void dfs_2(int u, int p){
    vector<ll> v;
    for(auto x : adj[u]){
        if(x != p){
            v.push_back(sub[x]);
        }
    }
    //begin : need to be improved in E2
    bitset<5005> bs;
    bs[0] = 1;
    int s = 0;
    for(int i=0;i<v.size();i++){
        bs |= (bs << v[i]);
        s += v[i];
    }
    int maxv = 0;
    for(int i=0;i<=s;i++){
        if(bs[i]){
            maxv = max(maxv, (s - i) * i);
        }
    }
    ans += maxv;
    v.clear();
    //end

    for(auto x : adj[u]){
        if(x != p){
            dfs_2(x, u);
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
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    dfs(1, 0);
    dfs_2(1, 0);
    cout << ans << "\n";
}
