#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N  = 2e5+3;

vector<int> adj[N];
vector<pair<int,int>> edges;

int p[N], sz[N];

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
    //freopen("in", "r", stdin); test input
    int n, m, d;
    cin >> n >> m >> d;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    init();
    for(int i=n;i>=2;i--){
        for(auto u : adj[i]){
            if(u == 1) continue;
            if(get(u) != get(i)) unite(u,i);
        }
    }
    vector<int> list;
    int cnt = 0;
    for(auto u : adj[1]){
        if(get(u) != get(1)){
            list.push_back(u);
            unite(u, 1);
            cnt++;
        }
    }
    if(cnt > d){
        cout << "NO";
    }else if(d > adj[1].size()){
        cout << "NO";
    }else{
        init();
        vector<pair<int,int>> ans;
        for(auto u : list){
            ans.emplace_back(1, u);
            unite(1, u);
        }
        for(auto u : adj[1]){
            if(cnt == d) break;
            if(get(u) != get(1)){
                cnt++;
                unite(1,u);
                ans.emplace_back(1,u);
            }
        }
        for(int i=2;i<=n;i++){
            for(auto u : adj[i]){
                if(u == 1) continue;
                if(get(u) != get(i)){
                    ans.emplace_back(i, u);
                    unite(i, u);
                }
            }
        }
        cout << "YES\n";
        for(auto u : ans) cout << u.first << " " << u.second << "\n";

    }
}   
