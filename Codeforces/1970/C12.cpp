#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int wl[N];
void dfs(int u, int p){
    bool h0 = false;
    for(auto v: adj[u]){
        if(v != p){
            dfs(v, u);
            if(wl[v] == 0) h0 = true;
        }
    }
    if(h0) wl[u] = 1;
    else wl[u] = 0;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=k;i++){
        int x;
        cin >> x;
        dfs(x, 0);
        if(wl[x]) cout << "Ron\n";
        else cout << "Hermione\n";
    }
}
