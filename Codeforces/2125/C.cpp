#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll func(ll n){
    vector<int> vx = {2, 3, 5, 7};
    ll ans = 0;
    for(int i=0;i<=15;i++){
        int p = 1;
        for(int j=0;j<4;j++){
            if(i & (1 << j)) p*= vx[j];
        }
        if(__builtin_popcount(i) % 2) ans -= n/p;
        else ans += n/p;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << func(r) - func(l-1) << "\n";
    }
}
