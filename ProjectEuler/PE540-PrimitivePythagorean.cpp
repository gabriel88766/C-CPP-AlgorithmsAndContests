//m² - n², 2mn, m² + n², being m and n coprime and at least one even.
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 60'000'000;
int lp[N+1];
vector<int> pr;
void sieve(){
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}


const ll num = 3141592653589793LL;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    ll ans = 0;
    for(ll i=2;i*i<= num; i++){
        vector<ll> pr;
        ll aux = i;
        while(aux != 1){
            if(pr.size() == 0 || pr.back() != lp[aux]) pr.push_back(lp[aux]);
            aux /= lp[aux];
        }
        ll lo = 0, hi = i-1;
        while(lo != hi){
            ll mid = lo + (hi - lo + 1)/2;
            if(mid*mid + i*i <= num) lo = mid;
            else hi = mid - 1;
        }
        if(i % 2 == 1){
            // for(ll j = 2; j <= lo; j += 2){
                // if(gcd(j, i) == 1) ans++;
            // }
            lo /= 2;
            ll tt = 0;
            for(int u=0;u<(1 << pr.size());u++){
                ll cp = 1;
                for(int v=0;v<pr.size();v++){
                    if(u & (1 << v)){
                        cp *= pr[v];
                    }
                }
                if(__builtin_popcount(u) % 2) tt -= lo / cp;
                else tt += lo / cp;
            }
            ans += tt;
        }else{
            //here don't need to divide by 2, cause i already is eliminating all multiples of 2
            // for(ll j = 1; j <= lo; j += 2){
            //     if(gcd(j, i) == 1) ans++;
            // }
            ll tt = 0;
            for(int u=0;u<(1 << pr.size());u++){
                ll cp = 1;
                for(int v=0;v<pr.size();v++){
                    if(u & (1 << v)){
                        cp *= pr[v];
                    }
                }
                if(__builtin_popcount(u) % 2) tt -= lo / cp;
                else tt += lo / cp;
            }
            ans += tt;

        }
    }
    cout << ans << "\n";
}
