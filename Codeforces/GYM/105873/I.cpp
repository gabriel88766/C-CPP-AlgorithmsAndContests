#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
int kv[N];
vector<int> adj[N];
vector<int> oc[N];
int ord[N], sub[N], cnt = 0;
void dfs(int u){
    ord[u] = ++cnt;
    oc[kv[u]].push_back(ord[u]);
    sub[u] = 1;
    for(auto v : adj[u]){
        dfs(v);
        sub[u] += sub[v];
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    vector<int> ak;
    for(int i=1;i<=n;i++){
        cin >> kv[i];
        ak.push_back(kv[i]);
    }
    sort(ak.begin(), ak.end());
    ak.resize(unique(ak.begin(), ak.end()) - ak.begin());
    for(int i=1;i<=n;i++){
        kv[i] = lower_bound(ak.begin(), ak.end(), kv[i]) - ak.begin();
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    for(int i=1;i<=q;i++){
        int x, k;
        cin >> x >> k;
        auto it = lower_bound(ak.begin(), ak.end(), k);
        if(it != ak.end() && *it == k){
            int idx = it - ak.begin();
            cout << lower_bound(oc[idx].begin(), oc[idx].end(), ord[x] + sub[x]) - lower_bound(oc[idx].begin(), oc[idx].end(), ord[x]) << "\n";
        }else cout << "0\n";
    }

}
