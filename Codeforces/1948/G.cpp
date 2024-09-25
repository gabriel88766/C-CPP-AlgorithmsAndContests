#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 21;   
int p[N], sz[N];

void init(){
    for(int i=0;i<N;i++) {p[i] = i; sz[i] = 1;}
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

int adj[21][21];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, c;
    cin >> n >> c;
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(adj[i][j]) vp.push_back({i, j});
        }
    }
    sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> v){
        return adj[u.first][u.second] < adj[v.first][v.second];
    });
    int ans = INF_INT;
    for(int i=1;i<(1 << n);i++){
        //this set is a minimum vertex cover. try kruskal
        init();
        //this is slow... may not pass
        vector<int> vt(n, false);
        int cur = __builtin_popcount(i) * c;
        int ed = 0;
        for(int k=0;k<n;k++){
            if(i & (1 << k)) vt[k] = true;
        }
        for(auto [x, y] : vp){
            if(vt[x] || vt[y]){
                if(get(x) != get(y)){
                    ed++;
                    unite(x, y);
                    cur += adj[x][y]; 
                }
            }
        }
        if(ed == n-1) ans = min(cur, ans);
    }
    cout << ans << "\n";
}
