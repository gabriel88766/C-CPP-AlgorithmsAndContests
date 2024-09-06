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
        int g = 0;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            g = gcd(g, x);
        }
        if(n == 1){
            if(g >= k) cout << k-1 << "\n";
            else cout << k << "\n";
            continue;
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            int jmp = g - 1;
            if(jmp >= k){
                ans = g*(i-1) + k;
                k = 0;
                break;
            }else{
                k -= jmp;
                ans = g*i;
            }
        }
        ans += k;
        cout << ans << "\n";
    }
}
