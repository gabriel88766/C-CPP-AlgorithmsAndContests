#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;
const int nMOD = 2;
const ull MOD[] = {(ull)1e9+123, (ull)1e9+7, (ull)1e9+123};
ull base;
vector<int> adj[N];
ull hashes[N][nMOD];
 
void init(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    base = uniform_int_distribution<int>(257, 1000000000)(rng);
}

void pre(int u, int p = -1){
    vector<ull> hash[nMOD];
    for(int i=0;i<nMOD;i++) hashes[u][i] = 69;
    for(auto v : adj[u]){
        if(v != p){
            pre(v, u);
            for(int i=0;i<nMOD;i++) hashes[u][i] = (hashes[u][i] + hashes[v][i] * hashes[v][i]) % MOD[i];
        }
    }
    for(auto v: adj[u]){
        if(v != p){
            for(int i=0;i<nMOD;i++) hash[i].emplace_back(hashes[v][i]);
        }
    }
    for(int i=0;i<nMOD;i++) sort(hash[i].begin(), hash[i].end());
    for(int i=0;i<nMOD;i++){
        ull pot = 1;
        for(int j=0;j<hash[i].size();j++){
            hashes[u][i] = (hashes[u][i] + pot*hash[i][j]) % MOD[i];
            pot = (pot * base) % MOD[i];
        }
    }
    for(int i=0;i<nMOD;i++) hash[i].clear();
}
 
bool sym(int rt, int p = -1){
    map<ull, int> mp;
    int cnt = 0;
    for(auto x : adj[rt]){
        if(p != x){
            mp[hashes[x][1]]++;
            cnt++;
        }
    }
    int cntodd = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it) if(it->second % 2) cntodd++;
    if(cntodd > 1) return false;
    else if(cntodd == 0 && !(cnt % 2)) return true;
    else if(cntodd == 0 && cnt % 2) return false;
    else if(cntodd == 1 && !(cnt % 2)) return false;
    else{
        for(auto x : adj[rt]){
            if(p != x){
                if(mp[hashes[x][1]] % 2) return sym(x, rt);
            }
        }
        return false; //unreachable;        
    }
}
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    init();
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<n;i++){
            int a,b;
            cin >> a >> b;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        pre(1);
        if(sym(1)) cout << "YES\n";
        else cout << "NO\n";
        for(int i=1;i<=n;i++) adj[i].clear();
    }
}