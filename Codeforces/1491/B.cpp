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
        int n, u, v;
        cin >> n >> u >> v;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int ans = 2e9+1;
        for(int i=0;i<n-1;i++){
            if(a[i] == a[i+1]){
                ans = min(ans, 2*v);
                ans = min(ans, u+v);
            }else if(abs(a[i] - a[i+1]) == 1){
                ans = min(ans, u);
                ans = min(ans, v);
            }else{  
                ans = 0;
            }
        }
        cout << ans << "\n";
    }
}
