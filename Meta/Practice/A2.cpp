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
    freopen("in", "r", stdin); //test input
    freopen("out", "w", stdout);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case #" << i << ": ";
        ll a, b, c;
        cin >> a >> b >> c;
        ll k = max(2*(c/b) - 1, 0LL);
        //if x > 0 then k = 2*y + x;
        //ax+by <= c
        if(b >= 2*a){
            k = max(k, c/a);
        }else{
            if(c >= a) k = max(2*((c-a)/b)+1, k);
        }
        cout << k;
        if(i != t) cout << "\n";

    }
}
