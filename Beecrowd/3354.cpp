#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1300031; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll L, R, N;
    cin >> L >> R >> N;
    while(L!= 0 || R != 0 || N != 0){
        vector<ll> val(N);
        for(int i=0;i<N;i++) cin >> val[i];
        ll ans = 0;
        for(int i=1;i< (1 << N); i++){
            int x = __builtin_popcountll(i);
            ll prod = 1;
            bool prodok = true;
            for(int j=0;j<N;j++){
                if(i & (1 << j)){
                    prod = (prod*val[j])/__gcd(prod,val[j]);
                }
                if(prod > 1000000000){
                    prodok = false;
                    break;
                }
            }
            if(!prodok) continue;
            ll fn = (L/prod)*prod;
            if(fn < L) fn += prod;
            ll ln = (R/prod)*prod;
            if(ln < fn) continue;
            ll sum = ((ln+fn)*((ln-fn)/prod+1))/2;
            if(x % 2){
                //sum
                ans += sum;
                ans %= MOD;
            }else{
                //minus
                ans -= sum;
                ans %= MOD;
                if(ans < 0) ans += MOD;
            }
        }
        cout << ans << "\n";

        cin >> L >> R >> N;
    }
}
