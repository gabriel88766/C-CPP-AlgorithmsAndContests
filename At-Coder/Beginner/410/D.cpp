#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<pair<int, int>> adj[1001];
bool rc[1001][1024];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    queue<pair<int, int>> qp;
    qp.push({1, 0});
    rc[1][0] = true;
    while(!qp.empty()){
        auto [u, val] = qp.front();
        qp.pop();
        for(auto &[v, c] : adj[u]){
            if(!rc[v][val ^ c]){
                rc[v][val ^ c] = true;
                qp.push({v, val^c});
            }
        }
    }
    int ans = -1;
    for(int i=0;i<1024;i++){
        if(rc[n][i]){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}
