#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;   
ll cnt[N], num[N];
int p[N];
ll ans[N], aux[N];
map<ll,ll> mp[N];
vector<int> adj[N], adjn[N];

void init(){
    for(int i=1;i<N;i++) {p[i] = i;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(mp[a].size() < mp[b].size()) swap(a,b);
    for(auto [k, v] : mp[b]){
        aux[a] -= mp[a][k] * v;
        mp[a][k] += v;
        aux[a] += (cnt[k] - mp[a][k]) * v;
    }
    p[b] = a;
}
void dfs(int u, int p){
    int ind = -1;
    aux[u] -= mp[u][num[u]];
    mp[u][num[u]]++;
    aux[u] += (cnt[num[u]] - mp[u][num[u]]);
    for(int i=0;i<adj[u].size();i++){
        auto v = adj[u][i];
        if(v != p){
            dfs(v, u);
            unite(v, u);
        }else{
            ind = adjn[u][i];
        }
    }
    if(ind != -1) ans[ind] = aux[get(u)];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num[i];
        cnt[num[i]]++;
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjn[a].push_back(i);
        adj[b].push_back(a);
        adjn[b].push_back(i);
    }
    dfs(1, 0);
    for(int i=1;i<n;i++) cout << ans[i] << " ";
    cout << "\n";
}
