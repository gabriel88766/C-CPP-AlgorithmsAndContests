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
        int n;
        cin >> n;
        ll as = 0, cs = 0;
        ll free = 0;
        for(int i=1;i<=n;i++){
            ll a, b, c;
            cin >> a >> b >> c;
            if(b >= a + c){
                as += a;
                cs += c;
            }else{
                ll ax = max(0LL, b-c); //let b-c;
                ll cx = max(0LL, b-a);
                as += ax;
                cs += cx;
                free += b - ax - cx;
            }
        }
        ll up = min(max(as, cs) - min(as, cs), free);
        if(free <= max(as, cs) - min(as, cs)){
            cout << min(as, cs) + free << "\n";
        }else{
            cout << max(as, cs) + (free - max(as,cs) + min(as, cs))/2 << "\n";
        }
    }
}
