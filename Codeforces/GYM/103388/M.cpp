#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
vector<int> adj[N];
int cnt = 0;
int ord[N], invord[N];

void dfs(int u){
    ord[u] = ++cnt;
    invord[cnt] = u;
    for(auto v : adj[u]) dfs(v);
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    int ans = 1;
    vector<pair<int,int>> vp;
    int c = 1;
    while(q--){
        int t, p;
        cin >> t >> p;
        vp.push_back({t, p});
        if(t == 1){
            adj[p].push_back(++c);
        }
    }
    dfs(1);
    c = 1;
    set<int> s;
    s.insert(1);
    for(auto [t, p] : vp){
        if(t == 1) s.insert(ord[++c]);
        else{
            s.erase(ord[p]);
            cout << invord[*s.begin()] << "\n";
        }
    }
}
