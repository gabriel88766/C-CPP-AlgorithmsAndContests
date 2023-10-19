#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

set<int> adj[2005];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
    }
    int ans = 0;
    for(int a=1;a<=2000;a++){
        for(auto b : adj[a]){
            for(auto c : adj[b]){
                if(c != a && !adj[c].count(a)) ans++;
            }
        }
    }
    cout << ans << "\n";
}
