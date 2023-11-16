#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 20000000;
vector<int> lp(N+1);
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
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    sieve();
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    //test if k is prime
    bool ok = true;
    for(int i=2;i*i<=k;i++){
        if(!(k % i)){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout << "0\n";
        return 0;
    }
    int l = (a-1)/k +1, r = b/k;
    // k > 100, count primes til 2*10^7
    // k <= 100, maybe easier, something like at most 2^24 * 24 algo.
    if(k > 100){
        for(int i = l; i<=r;i++){
            if(lp[i] >= k) ans++;
            if(i == 1) ans++;
        }
        
    }else{
        vector<int> p;
        for(auto x : pr){
            if(x < k) p.push_back(x);
            else break;
        }
        int sz = p.size();
        ans = r - l + 1;
        for(int i=1; i < (1 << sz); i++){
            int pos = __builtin_popcount(i);
            ll num = 1;
            for(int j=0;j<sz;j++){
                if(i & (1 << j)){
                    num *= p[j];
                }
                if(num > 2000000000) break;
            }
            if(num > 2000000000) continue;
            if(pos % 2){
                ans -= r/num - (l-1)/num;
            }else{
                ans += r/num - (l-1)/num;
            }
        }
    }
    cout << ans << "\n";

}
