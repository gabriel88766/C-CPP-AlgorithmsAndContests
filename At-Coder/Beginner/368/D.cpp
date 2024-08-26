#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+1;
set<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    set<int> drm;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        drm.insert(x);
    }
    stack<int> lf;
    for(int i=1;i<=n;i++){
        if(adj[i].size() == 1) lf.push(i);
    }
    int rmc = 0;
    while(!lf.empty()){
        auto u = lf.top();
        lf.pop();
        if(!drm.count(u)){
            rmc++;
            int v = *adj[u].begin();
            adj[v].erase(u);
            if(adj[v].size() == 1) lf.push(v);
        }
    }
    cout << n - rmc << "\n";
}
