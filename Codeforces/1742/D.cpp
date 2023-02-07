#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


vector<int>  cop[1001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            if(__gcd(i, j) == 1) cop[i].push_back(j);
        }
    }
    while(t--){
        int n;
        cin >> n;
        vector<int> g(1001, 0), v(n);
        for(int i=0;i<n;i++){
            int aux;
            cin >> v[i];
            g[v[i]] = i+1;
        }
        int ans = -1;
        for(int i=0;i<n;i++){
            int x = v[i];
            for(auto u : cop[x]){
                if(g[u]){
                    ans = max(ans, g[u] + i + 1);
                } 
            }
        }
        cout << ans << "\n";

        
    }
}
