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
        int n, x, y;
        cin >> n >> x >> y;
        vector<ll> ans(n+1);
        for(int i=y;i<=x;i++) ans[i] = 1;
        for(int i=x+1;i<=n;i++){
            int aux = i - (x+1);
            if(aux % 2) ans[i] = 1;
            else ans[i] = -1;
        }
        for(int i=y-1;i>=1;i--){
            int aux = y-1 - i;
            if(aux % 2) ans[i] = 1;
            else ans[i] = -1;
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }

}
