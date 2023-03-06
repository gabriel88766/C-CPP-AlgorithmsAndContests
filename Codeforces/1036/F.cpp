#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll MAX_LL = 4e18;
ll hi_v[62], mi[62], pr[62];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //preprocessing bin search.
    for(int i=2;i<=60;i++){
        ll lo = 1, hi = 1e9+2, curpt, mid;
        while(lo != hi){
            mid = (lo+hi)/2;
            curpt = mid;
            bool ok = true;
            for(int j=1;j<i;j++){
                if(MAX_LL/curpt < mid){
                    ok = false;
                    break;
                }
                curpt *= mid;
            }
            if(ok) lo = mid+1;
            else hi = mid;
        }
        lo--;
        hi_v[i] = lo;
    }
    //preprocessing mobius
    for(ll i =2; i<=60;i++) mi[i] = 1;
    for(ll i=2; i<=60; i++){
        if(!pr[i]){
            for(ll j = i; j <= 60; j += i){
                pr[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j <= 60; j += i*i){
                mi[j] = 0;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        ll num;
        cin >> num;
        ll ans = num;
        for(int i=2;i<=60;i++){
            ll lo = 1, hi = hi_v[i], mid;
            while(lo != hi){
                mid = (lo+hi)/2;
                ll cur = mid;
                for(int j=2;j<=i;j++) cur *= mid;
                if(cur > num) hi = mid;
                else lo = mid+1;
            }
            ll curlo = lo;
            for(int j=2;j<=i;j++) curlo *= lo;
            if(curlo > num) lo--;
            ans += mi[i] * (lo-1);
        }
        ans--;
        cout << ans << "\n";
    }
}
