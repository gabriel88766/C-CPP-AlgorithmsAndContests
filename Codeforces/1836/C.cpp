#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int fnum[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        ll k;
        cin >> a >> b >> c >> k;
        ll S = 0;
        bool ok = false;
        for(ll i=fnum[a]; i<fnum[a+1]; i++){
            ll lo = fnum[b], hi = fnum[b+1]-1;
            lo = max(lo, fnum[c]-i);
            hi = min(hi, fnum[c+1]-i-1);
            if(hi >= lo){
                ll cur = hi - lo + 1;
                if(S + cur >= k){
                    lo += (k-S)-1;
                    cout << i << " + " << lo << " = " << i+lo << "\n";
                    ok = true;
                    break; 
                }else S += cur;
            }
        }
        if(!ok) cout << "-1\n";
    }
}
