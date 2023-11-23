#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;   
int p[N], sz[N];
vector<int> adj[N], adjw[N];
void init(){
    for(int i=1;i<N;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    init();
    for(int i=0;i<m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adjw[a].push_back(w);
        adj[b].push_back(a);
        adjw[b].push_back(w);
        unite(a, b);
    }
    if(get(1) == get(n)){
        vector<pair<string, int>> ansv;
        ll ans = 0;
        set<int> s;
        s.insert(n);
        while(s.size() < n && !s.count(1)){
            int minv = INF_INT;
            for(auto u : s){
                for(int i=0;i<adj[u].size();i++){
                    int v = adj[u][i];
                    int w = adjw[u][i];
                    if(s.count(v)) continue;
                    minv = min(minv, w);
                }
            }
            string st;
            for(int i=1;i<=n;i++){
                if(s.count(i)) st += '0';
                else st += '1';
            }
            ans += minv;
            ansv.push_back({st, minv});
            vector<int> ins;
            for(auto u : s){
                for(int i=0;i<adj[u].size();i++){
                    int &v = adj[u][i];
                    int &w = adjw[u][i];
                    if(s.count(v)) continue;
                    w -= minv;
                    if(w == 0) ins.push_back(v);
                }
            }
            for(auto x : ins) s.insert(x);
        }





        cout << ans << " " << ansv.size() << "\n";
        for(auto [s, qt] : ansv) cout << s << " " << qt << "\n";
    }else cout << "inf\n";

}
