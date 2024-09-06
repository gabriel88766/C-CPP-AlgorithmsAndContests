#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+2;
vector<int> adj[N];
int sub[N], par[N];

void dfs(int u){
    sub[u] = 1;
    for(auto v : adj[u]){
        dfs(v);
        sub[u] += sub[v];
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
        int n, q;
        cin >> n >> q;
        for(int i=2;i<=n;i++){
            cin >> par[i];
            adj[par[i]].push_back(i);
        }
        dfs(1);
        vector<int> p(n+1), ip(n+1);
        for(int i=1;i<=n;i++){
            cin >> p[i];
            ip[p[i]] = i;
        }
        set<int> okv;
        for(int i=1;i<=n;i++){
            bool ok = true;
            //first check
            if(ip[i] + sub[i] - 1 > n) ok = false;
            else{
                int fp = ip[i] + 1;
                for(int j=0;j<adj[i].size();j++){
                    if(par[p[fp]] != i){
                        ok = false;
                        break;
                    }else{
                        fp += sub[p[fp]];
                    }
                }
            }
            if(ok) okv.insert(i);
        }
        for(int i=0;i<q;i++){
            int a, b;
            cin >> a >> b;
            swap(ip[p[a]], ip[p[b]]);
            swap(p[a], p[b]);
            vector<int> chk = {p[a], p[b]};
            if(par[p[a]] ) chk.push_back(par[p[a]]);
            if(par[p[b]]) chk.push_back(par[p[b]]);
            for(auto x : chk){
                bool ok = true;
                if(ip[x] + sub[x] - 1 > n) ok = false;
                else{
                    int fp = ip[x] + 1;
                    for(int j=0;j<adj[x].size();j++){
                        if(par[p[fp]] != x){
                            ok = false;
                            break;
                        }else{
                            fp += sub[p[fp]];
                        }
                    }
                }
                if(ok) okv.insert(x);
                else okv.erase(x);
            }
            if(okv.size() == n) cout << "YES\n";
            else cout << "NO\n";

        }



        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }
}
