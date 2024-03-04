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
        int n, k;
        cin >> n >> k;
        int ln = 0;
        vector<int> ans(n+1);
        for(int i=1;i<=k;i++){
            int cn, st;
            if(i % 2){
                st = 1;
                cn = ln + 1;
                ln += n % k >= i ? 1 : 0;
                ln += n/k;
            }else{
                st = -1;
                ln += n % k >= i ? 1 : 0;
                ln += n/k;
                cn = ln;
            }
            for(int j = i; j <= n; j += k){
                ans[j] = cn;
                cn += st;
            }
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
    }
}
