#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll func(ll n, ll k){
    for(int i=0;;i++){
        ll cp = 1LL << i;
        ll co = n/cp - n/(2*cp);
        if(co >= k){
            return cp * (2*k - 1);
        }else k -= co;
    }
    assert(1 == 0);
    return -1;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        cout << func(n, k) << "\n";
        
    }
}
