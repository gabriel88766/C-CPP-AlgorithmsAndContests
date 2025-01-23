#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 300005;
vector<int> adj[N];
int p[N];
vector<pair<ll, ll>> vec[N];
ll ans = 0;
void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; vec[i].clear(); vec[i].push_back({1, 1});}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(vec[a].size() < vec[b].size()) swap(a,b);
    p[b] = a;
    ll aux = 0; //sum of lower
    for(int i=0;i<vec[b].size();i++){
        int j = vec[b].size() - i - 1;
        int k = vec[a].size() - i - 1;
        //a is lower
        ans += aux * vec[b][j].first;
        //b is lower than or equal
        if(i > 0) ans += (2*i - 1) * vec[a][k].second * vec[b][j].first;
        if(i > 0) aux += (2*i - 1) * vec[a][k].first; 
        vec[a][k].first += vec[b][j].first;
        vec[a][k].second += vec[b][j].second;
    }
}


void clear(int n){
    ans = 0;
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }
}


void dfs(int u, int p = 0){
    for(auto &v : adj[u]){
        if(v != p){
            dfs(v, u);
            vec[get(v)].push_back({0, vec[get(v)].back().second});
            unite(v, u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        init(n);
        for(int i=1;i<n;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        cout << ans << "\n";
        clear(n);
    }

}