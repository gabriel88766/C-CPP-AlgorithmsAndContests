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
        int l, r, x, a, b;
        cin >> l >> r >> x;
        cin >> a >> b;

        int ans = 0;
        if(abs(a-b) >= x){
            ans = 1;
        }else if(a > b || a < b){
            bool tol = false, tor = false, fl = false, fr = false;
            if(abs(r-a) >= x) tor = true;
            if(abs(l-a) >= x) tol = true;
            if(abs(l-b) >= x) fl = true;
            if(abs(r-b) >= x) fr = true;
            if(fr && tor) ans = 2;
            else if(fl && tol) ans = 2;
            else if(fl && tor) ans = 3;
            else if(fr && tol) ans = 3;
            else ans = -1;
        }
        cout << ans << "\n";
    }
}
