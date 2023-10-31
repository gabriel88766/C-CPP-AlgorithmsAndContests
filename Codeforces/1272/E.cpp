#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N], invadj[N];
int d1[N], d0[N];
//cout << fixed << setprecision(6)
vector<int> v1, v0;

void bfs(int *d, vector<int> &v){
    queue<int> q;
    for(auto x : v){
        q.push(x);
        d[x] = 0;
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1);
    
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(i + v[i] <= n){
            adj[i + v[i]].push_back(i);
        }
        if(i - v[i] >= 1){
            adj[i - v[i]].push_back(i);
        }
        if(v[i] % 2) v1.push_back(i);
        else v0.push_back(i);
    }
    memset(d1, 63, sizeof(d1));
    memset(d0, 63, sizeof(d0));
    bfs(d0, v0);
    bfs(d1, v1);
    vector<int> ans(n+1, -1);
    for(auto x : v0){
        if(d1[x] != INF_INT) ans[x] = d1[x];
    }
    for(auto x : v1){
        if(d0[x] != INF_INT) ans[x] = d0[x];
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}
