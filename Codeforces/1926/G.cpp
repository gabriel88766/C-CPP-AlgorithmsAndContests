#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> adj[N];
char typ[N];
bool sc[N], pc[N], wc[N];
int ans = 0;
void dfs(int u){
    for(auto v : adj[u]) dfs(v);
    bool hp = false, hs = false;
    for(auto v : adj[u]){
        if(sc[v]) hs = true;
        if(pc[v]) hp = true;
    }
    if(typ[u] == 'S') hs = true;
    if(typ[u] == 'P') hp = true;
    if(hs && !hp) sc[u] = true;
    else if(!hs && hp) pc[u] = true;
    else if(hs && hp){
        //block all P (if typ[u] != P) or block all S (if typ[u] != S)
        int cntp = 0, cnts = 0, cntw = 0;
        for(auto v : adj[u]){
            if(pc[v]) cntp++;
            else if(sc[v]) cnts++; 
            else if(wc[v]) cntw++;
        }
        if(typ[u] == 'P'){
            ans += cnts; //all w become p
            pc[u] = true;
        }else if(typ[u] == 'S'){
            ans += cntp; //all w become s
            sc[u] = true;
        }else{
            if(cntp < cnts){ //all w become s
                ans += cntp;
                sc[u] = true;
            }else if(cntp > cnts){ //all w become p
                ans += cnts;
                pc[u] = true;
            }else{ //wildcard
                ans += cnts;
                wc[u] = true;
            }
        }
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
        int n;
        cin >> n;
        for(int i=2;i<=n;i++){
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
        for(int i=1;i<=n;i++) cin >> typ[i];
        dfs(1);
        cout << ans << "\n";
        //clear()
        ans = 0;
        for(int i=1;i<=n;i++){
            typ[i] = sc[i] = wc[i] = pc[i] = 0;
            adj[i].clear();
        }
    }
}
