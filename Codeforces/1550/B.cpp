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
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        if(b >= 0){
            //then the best strategy is delete one by one
            int ans = n * (a + b);
            cout << ans << "\n";
        }else{
            //then the best strategy is make the minimal number of ops
            int ans = n * a;
            int flip = 0;
            char lc = '-';
            for(auto c : s){
                if(c != lc){
                    flip++;
                    lc = c;
                }
            }
            ans += (flip/2 + 1) * b;
            cout << ans << "\n";
        }
    }
}
