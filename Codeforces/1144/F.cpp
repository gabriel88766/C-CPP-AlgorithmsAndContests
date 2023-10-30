#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> adj[N];
int d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edgs;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edgs.push_back({a,b});
    }
    bool ok = true;
    queue<int> q;
    q.push(1);
    memset(d, 0xFF, sizeof(d));
    d[1] = 0;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(d[v] == -1){
                d[v] = d[u] ^ 1;
                q.push(v);
            }else{
                if(d[v] != (d[u] ^ 1)) ok = false;
            }
        }
    }
    if(ok){
        cout << "YES\n";
        for(auto [x, y] : edgs){
            if(d[x] == 1) cout << "0";
            else cout << "1";
        }
    }else cout << "NO\n";
}
