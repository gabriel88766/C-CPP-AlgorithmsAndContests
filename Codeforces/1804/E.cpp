#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[1 << 20][20];
int p[1 << 20][20];
bool adj[20][20];
bool okmsk[1 << 20];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a-1][b-1] = adj[b-1][a-1] = true;
    }
    //preprocessing O(n^2 2^n), fast enough? yes!
    bool ok2 = false;
    int fi, si;
    for(int i=1;i<(1 << n);i++){
        vector<bool> ok(n, false);
        for(int j=0;j<n;j++){
            if(i & (1 << j)){
                ok[j] = true;
                for(int k=0;k<n;k++){
                    if(adj[j][k]) ok[k] = true;
                }
            }
        }
        okmsk[i] = true;
        for(int j=0;j<n;j++) if(!ok[j]) okmsk[i] = false;
        if(__builtin_popcount(i) == 2 && okmsk[i]){
            for(int j=0;j<n;j++){
                if(i & (1 << j)){
                    fi = j;
                    break;
                }
            }
            for(int j=fi+1;j<n;j++){
                if(i & (1 << j) ){
                    if(adj[fi][j]){
                        si = j;
                        ok2 = true;
                    }
                }
            }
            if(ok2) break;
        }
    }
    if(ok2){
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i == fi || i == si){
                ans[i] = (i == fi) ? si : fi;
            }else{
                if(adj[i][fi]) ans[i] = fi;
                else ans[i] = si;
            }
        }
        cout << "Yes\n";
        for(int i=0;i<n;i++) cout << ans[i]+1 << " ";
    }else{
        for(int i=n-1;i>=2;i--){
            memset(dp, 0, sizeof(dp));
            for(int j=0;j<i;j++) if(adj[i][j]) {dp[1 << j][j] = true, p[1 << j][j] = i;}
            for(int j=1;j<(1 << i); j++){
                int popcnt = __builtin_popcount(j);
                if(popcnt == 1) continue;
                for(int k=0;k<i;k++){
                    if(j & (1 << k)){
                        int last = j ^ (1 << k);
                        for(int u=0;u<i;u++){
                            if(u == k) continue;
                            if((last & (1 << u)) && adj[u][k] && dp[last][u]){
                                dp[j][k] = true;
                                p[j][k] = u;
                            }
                        }            
                    }
                }
                if(!okmsk[j | (1 << i)]) continue;
                for(int k=0;k<i;k++){
                    if((j & (1 << k)) && adj[k][i] && dp[j][k]){
                        //match!
                        vector<int> cycle;
                        set<int> sc;
                        cycle.push_back(i);
                        sc.insert(i);
                        int aux = k;
                        int state = j;
                        while(aux != i){
                            cycle.push_back(aux);
                            sc.insert(aux);
                            int naux = p[state][aux];
                            state ^= (1 << aux);
                            aux = naux;
                        }
                        cycle.push_back(i);
                        vector<int> ans(n);
                        for(int u = 0;u<n;u++){
                            if(sc.count(u)) continue;
                            for(int w=0;w<n;w++){
                                if(adj[u][w] && sc.count(w)) ans[u] = w;
                            }
                        }
                        for(int u=0;u<cycle.size()-1;u++){
                            ans[cycle[u]] = cycle[u+1];
                        }
                        cout << "Yes\n";
                        for(int i=0;i<n;i++) cout << ans[i]+1 << " ";
                        return 0;
                    }
                }
            }
        }
        cout << "No\n";
    }
}
