#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll tim[N];
bool vis[N];
vector<int> mv[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> tim[i] >> x;
        for(int j=0;j<x;j++){
            int u;
            cin >> u;
            mv[i].push_back(u);
        }
    }
    queue<int> q;
    q.push(n);
    vis[n] = true;
    ll ans = 0;
    while(q.size()){
        auto u = q.front();
        q.pop();
        ans += tim[u];
        for(auto v : mv[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << ans << "\n";
}
