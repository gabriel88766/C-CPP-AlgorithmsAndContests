#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        vector<bool> vis(n+1, false);
        int p = 1;
        bool ok = true;
        for(int i=1;i<=m;i++){
            int x;
            cin >> x;
            if(!vis[x]){
                if(v[p] == x){
                    vis[x] = true;
                    p++;
                }else{
                    ok = false;
                }
            }
        }
        if(ok) cout << "YA\n";
        else cout << "TIDAK\n";
    }
}
