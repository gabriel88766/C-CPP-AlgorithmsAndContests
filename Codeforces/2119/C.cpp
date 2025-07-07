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
        ll n, l, r, k;
        cin >> n >> l >> r >> k;
        if(n % 2) cout << l << "\n";
        else if(n == 2) cout << "-1\n";
        else{
            ll x = l & r;
            if(x && __builtin_clzll(x) == __builtin_clzll(r)){
                //last bit can't be erased, thus and has bit and xor don't
                cout << "-1\n";
            }else{
                //l l l l l l l l l l {3 more to go} xor is l, and is l
                ll rx = 1LL << (64 - __builtin_clzll(l));
                if(k >= n-1) cout << rx << "\n";
                else cout << l << "\n";
            } 
        }
    }
}
