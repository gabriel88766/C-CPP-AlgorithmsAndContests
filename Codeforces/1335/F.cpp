#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;   
int p[N], sz[N];
int v[N], d[N], nxt[N], mod[N], cl[N];
int n, m;
vector<int> comp[N], cmps;

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; v[i] = d[i] = mod[i] = 0; comp[i].clear(); cmps.clear();}
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

pair<int,int> fromC(int u){
    u--;
    return make_pair(u/m, u % m);
}
int toC(pair<int,int> p){
    return p.first*m + p.second + 1;
}

void dfs(int u){
    int cur = u;
    while(!v[cur]){
        v[cur] = 1;
        cur = nxt[cur];
    }
    if(v[cur] == 1){
        while(v[cur] == 1){
            v[cur] = 2;
            mod[nxt[cur]] = mod[cur] + 1;
            cur = nxt[cur];
        }
        cl[get(cur)] = mod[cur];
        mod[cur] = 0;
    }
    cur = u;
    while(v[cur] == 1){
        d[u]++;
        cur = nxt[cur];
    }
    d[u] += d[cur];
    cur = u;
    while(v[cur] == 1){
        v[cur] = 3;
        d[nxt[cur]] = d[cur] - 1;
        cur = nxt[cur];
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<char>> col(n, vector<char>(m));
        vector<vector<char>> dir(n, vector<char>(m));
        init(n * m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> col[i][j];
            }
        }
        //cell i,j  <-> m*i + j + 1 vertex
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> dir[i][j];
                int id = i, jd = j;
                if(dir[i][j] == 'U') id--;
                if(dir[i][j] == 'D') id++;
                if(dir[i][j] == 'R') jd++;
                if(dir[i][j] == 'L') jd--;
                int u = toC({i, j});
                int v = toC({id, jd});
                unite(u, v);
                nxt[u] = v;
            }
        }
        for(int i=1;i<=n*m;i++){
            if(!comp[get(i)].size()) cmps.push_back(get(i));
            comp[get(i)].push_back(i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[toC({i, j})]){
                    dfs(toC({i, j}));
                }
            }
        }
        int ans1 = 0, ans2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[toC({i, j})] == 2){
                     ans1++;
                }
            }
        }
        for(auto x : cmps){
            vector<vector<int>> ds(comp[x].size());
            vector<bool> ok(cl[x], false);
            for(auto y : comp[x]){
                ds[d[y]].push_back(y);
            }
            for(int i=0;i<ds.size();i++){
                for(int j=0;j<ds[i].size();j++){
                    auto u = ds[i][j];
                    auto [ii, jj] = fromC(u);
                    if(i != 0){
                        mod[u] = mod[nxt[u]] - 1;
                        if(mod[u] < 0) mod[u] += cl[x];
                    }
                    if(col[ii][jj] == '0') ok[mod[u]] = true;
                }
            }
            for(int i=0;i<cl[x];i++) if(ok[i]) ans2++;
        }
        cout << ans1 << " " << ans2 << "\n";
        
    }
}
