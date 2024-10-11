#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 100005, M = 18; // M >= log2(N)
bool sparse[M][N][M];
vector<bool> v[18];

void build(vector<bool> &v, int cs){
    int n = v.size();
    for(int i=0;i<n;i++) sparse[cs][i][0] = v[i];
    for(int j = 1; j < M; j++){
        for(int i = 0; i < n; i ++){
            if((i + (1 << (j-1))) < n) sparse[cs][i][j] = max(sparse[cs][i][j-1], sparse[cs][i + (1 << (j-1))][j-1]);
            else sparse[cs][i][j] = sparse[cs][i][j-1];
        }
    }
}

int query(int a, int b, int cs){
    if(a == b) return sparse[cs][a][0]; //bug
    int pot = 32 - __builtin_clz(b - a) - 1; 
    return max(sparse[cs][a][pot], sparse[cs][b - (1 << pot) + 1][pot]);
}

vector<int> ind[17];
int adj[17][17];
bool alw[1 << 17];
bool vis[1 << 17];
bool mtc[1 << 17][17][17];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, p;
    string s;
    cin >> n >> p >> s;
    
    for(int i=0;i<(1<<p);i++){
        alw[i] = true;
    }
    for(int i=0;i<p;i++) v[i].resize(n);
    for(int i=0;i<n;i++){
        ind[s[i] - 'a'].push_back(i);
        v[s[i]-'a'][i] = 1;
    }
    
    for(int i=0;i<p;i++) build(v[i], i);
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            cin >> adj[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            //try to make i adjacent to next j (just need to see next)
            int cl = s[i] - 'a';
            if(adj[cl][j]) continue; //allowed
            auto it = upper_bound(ind[j].begin(), ind[j].end(), i);
            if(it == ind[j].end()) continue;
            int msk = (1 << p) - 1;
            for(int k=0;k<p;k++){
                if(k == cl || k == j) continue;
                if(query(i, *it, k) == 1) msk ^= (1 << k);
            }
            mtc[msk][j][cl] = true;
            
        }
    }
    int ini = (1 << p) - 1;
    for(int m=ini;m>=0;m--){
        bool ok = false;
        for(int j=0;j<p;j++){
            for(int k=0;k<p;k++){
                if(mtc[m][j][k]){
                    alw[m] = false;
                    for(int u=0;u<p;u++){
                        if(u != j && u != k && (m & (1 << u))) mtc[m ^ (1 << u)][j][k] = true;
                    }
                }
            }
        }
    }
    queue<int> q;
    q.push(ini);
    int ans = n;
    vis[ini] = true;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        int cur = 0;
        for(int j=0;j<p;j++) if(u & (1 << j)) cur += ind[j].size();
        ans = min(ans, cur);
        for(int j=0;j<p;j++){
            if(u & (1 << j)){
                int nm = u ^ (1 << j);
                if(alw[nm] && !vis[nm]){
                    q.push(nm);
                    vis[nm] = true;
                }
            }
        }
    }
    cout << ans << "\n";

}
