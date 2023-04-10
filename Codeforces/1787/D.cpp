#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
const int N = 2e5+3;
int vis[N];
int v[N], rc[N], rc1[N], indg[N];

int cnt = 0;
vector<int> cur;
int dfs(int u){
    vis[u] = 1;
    cur.push_back(u);
    if(v[u] == 0) return 0;
    else if(!vis[v[u]]){
        return dfs(v[u]);
    }else{
        if(vis[v[u]] == 1){
            int nxt = v[u];
            do{
                nxt = v[nxt];
            }while(nxt != v[u]);
            return 1;
        }else{
            return rc[v[u]];
        }
    }
}

int dfs2(int u, int cnt = 1){
    rc1[u] = true;
    if(v[u] && !rc1[v[u]]) return dfs2(v[u], cnt+1);
    else return cnt;
}

int sub[N];
vector<int> inv[N];
void dfs3(int u){
    sub[u]++;
    for(auto v : inv[u]){
        dfs3(v);
        sub[u] += sub[v];
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n;
        ll ans = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            v[i] += i;
            if(v[i] <= 0 || v[i] > n) v[i] = 0;
            else{
                indg[v[i]]++;
                inv[v[i]].push_back(i);
            }
        }
        
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int x = dfs(i);
                while(!cur.empty()){
                    rc[cur.back()] = x;
                    vis[cur.back()] = 2;
                    cur.pop_back();
                }
            }
        }
        ll k = dfs2(1);
        if(rc[1]){
            ans = k*(2*n+1);
            ans -= k*k;
            for(int i=1;i<=n;i++){
                if(rc1[i]) continue;
                else{
                    if(rc[i]) ans -= k;
                }
            }
        }else{ 
            //change others freely
            ans += (2*n+1)*n;
            int last = 1;
            while(v[last]) last = v[last];
            dfs3(last);
            for(int i=1;i<=n;i++){
                if(!rc1[i]){
                    if(rc[i]) ans -= k;
                }else{
                    ans -= sub[i];
                }
            }
        }
        
        cout << ans << "\n";
        //clear
        for(int i=1;i<=n;i++) {vis[i] = rc[i] = rc1[i] = indg[i] = sub[i] = 0; inv[i].clear();}
    }
    
}
