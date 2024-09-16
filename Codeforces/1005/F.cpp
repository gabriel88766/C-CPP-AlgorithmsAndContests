#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<pair<int,int>> edgs;
vector<int> adj[N];
int d[N];
vector<int> par[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    edgs.resize(m+1);
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(i);
        adj[b].push_back(i);
        edgs[i] = {a, b};
    }
    memset(d, 63, sizeof(d));
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto i : adj[u]){
            auto [x, y] = edgs[i];
            int v = (x == u ? y : x);
            if(d[v] > d[u] + 1){
                q.push(v);
                d[v] = d[u] + 1;
                par[v].push_back(i);
            }else if(d[v] == d[u] + 1){
                par[v].push_back(i);
            }
        }
    }
    vector<int> cur(n+1, 0);
    vector<string> anst;
    for(int i=0;i<k;i++){
        string ans(m, '0');
        for(int j=2;j<=n;j++){
            ans[par[j][cur[j]] - 1] = '1';
        }
        anst.push_back(ans);
        bool ok = false;
        for(int j=n;j>=2;j--){
            if(cur[j] == par[j].size() - 1){
                cur[j] = 0;
            }else{
                cur[j]++;
                ok = true;
                break;
            }
        }
        if(!ok) break;
    }
    cout << anst.size() << "\n";
    for(auto x : anst) cout << x << "\n";
}
