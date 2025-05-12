#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 4004;
ll dp[N]; //initially 0 because cpp.
int adj[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> vt;
    for(int j=0;j<m;j++){
        int a, b, c;
        cin >> a >> b >> c;
        if(adj[a][b] != 0 && adj[a][b] != c){
            cout << "-1";
            return 0;
        }
        adj[a][b] = c;
        vt.push_back({a-1, b, c});
        vt.push_back({b, a-1, -c});
    }
    for(int i=0;i<n;i++) if(adj[i+1][i+1] == 0) vt.push_back({i, i+1, 1});
    bool ok = false;
    for(int i=1;i<=n+1;i++){
        bool cok = true;
        for(auto &[a, b, c] : vt){
            if(dp[b] < dp[a] + c){
                dp[b] = dp[a] + c;
                cok = false;
            }
        }
        if(cok) ok = true;
    }
    if(ok) cout << dp[n] << "\n";
    else cout << "-1\n";
}
