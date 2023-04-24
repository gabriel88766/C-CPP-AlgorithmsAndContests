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
        ll n;
        cin >> n;
        if(n == 2){
            cout << "1\n";
            continue;
        }
        int ans = 2; //10 for n and 11 for n-1;
        ll pot2 = 2;
        for(int i=2;i<62;i++){
            pot2 *= 2;
            if(pot2 > n) break;
            ll lo = 2, hi = 1e9, mid;
            while(lo != hi){
                mid = lo + (hi-lo+1)/2;
                if(pow(mid, i) > 4e18){
                    hi = mid-1;
                    continue;
                }
                ll cur = 1;
                for(int j=0;j<i;j++) cur *= mid;
                if(cur <= n) lo = mid;
                else hi = mid-1;
            }
            ll pot = 1;
            for(int j=0;j<i;j++) pot *= lo;
            ll aux = n;
            bool ok = true;
            while(aux){
                ll x = aux / pot;
                if(x > 1){
                    ok = false;
                    break;
                }
                aux -= x * pot;
                pot /= lo;
            }
            if(ok) ans++;
        }
        cout << ans << "\n";
    }
}
