#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 3e5+3;
bool ok[N];
int cn[N], bl[N], par[N];
vector<int> adj[N];
void dfs(int u, int p){
    par[u] = p;
    if(ok[u]) cn[u] += 1;
    for(auto v : adj[u]){
        if(v != p){
            dfs(v, u);
            cn[u] += cn[v];
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    int ttn = 0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        cin >> bl[i];
        if(bl[i] == 1){
            ttn++;
            ok[i] = true;
            q.push(i);
        }
    }
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    while(q.size()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(!ok[v]){
                if(bl[u] == 1){
                     ok[v] = true;
                     q.push(v);
                }else{
                    if(par[u] == v){
                        if(cn[u] >= 2){
                            ok[v] = true;
                            q.push(v);
                        } 
                    }
                    else if(ttn - cn[v] >= 2){
                        ok[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ok[i] << " ";
    cout << "\n";
}
