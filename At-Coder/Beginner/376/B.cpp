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
    int n, q;
    cin >> n >> q;
    int ans = 0;
    int l = 1, r = 2;
    for(int i=0;i<q;i++){
        char c;
        int d;
        cin >> c >> d;
        if(c == 'L'){
            if(max(d, l) > r && min(d, l) < r) ans += n - (abs(d-l));
            else ans += abs(d-l);
            l = d;
        }else{
            if(max(d, r) > l && min(d, r) < l) ans += n - abs(d - r);
            else ans += abs(d-r);
            r = d;
        }
    }
    cout << ans << "\n";
}
