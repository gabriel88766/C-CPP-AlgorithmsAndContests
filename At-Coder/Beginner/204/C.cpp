#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<int> adj[N];
int rc[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        memset(rc, 0, sizeof(rc));
        rc[i] = true;
        queue<int> q;
        q.push(i);
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(auto v : adj[u]){
                if(!rc[v]){
                    rc[v] = true;
                    q.push(v);
                }
            }
        }
        for(int j=1;j<=n;j++) if(rc[j]) ans++;
    }
    cout << ans << "\n";
}
