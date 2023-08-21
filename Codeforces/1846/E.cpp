#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll hiv[59];
const ll maxN = 1e18;

void init(){
    // i == 2
    ll lo = 1, hi = 1e9, mid;
    while(lo != hi){
        mid = lo + (hi-lo+1)/2;
        if(1 + mid + mid*mid > maxN) hi = mid-1;
        else lo = mid;
    }
    hiv[2] = lo;
    // i == 3
    lo = 1, hi = 1e6, mid;
    while(lo != hi){
        mid = lo + (hi-lo+1)/2;
        if(1+mid+mid*mid+mid*mid*mid > maxN) hi = mid-1;
        else lo = mid;
    }
    hiv[3] = lo;
    for(int i=4;i<59;i++){
        for(int j=2; ; j++){
            bool ok = true;
            ll S = 1, cur = 1;
            for(int k=1;k<=i;k++){
                if(maxN/cur < j){
                    ok = false;
                    break;
                }else{
                    cur *= j;
                }
                if(S + cur > maxN){
                    ok = false;
                    break;
                }
                S += cur;
            }
            if(!ok){
                hiv[i] = j-1;
                break;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    init();
    while(t--){
        ll n;
        cin >> n;
        bool ok = false;
        for(int i=2;i<=58;i++){
            ll lo = 2, hi = hiv[i], mid;
            while(lo != hi){
                mid = lo + (hi - lo + 1)/2;
                ll cur = 1, S = 1;
                for(int j=1;j<=i;j++){
                    cur *= mid;
                    S += cur;
                }
                if(S <= n) lo = mid;
                else hi = mid - 1;
            }
            ll cur = 1, S = 1;
            for(int j=1;j<=i;j++){
                cur *= lo;
                S += cur;
            }
            if(S == n){
                ok = true;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
