//unsolved;
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> s(n+1);
        for(ll i=1;i<=n;i++) cin >> s[i];
        vector<ll> ps(s[n]+1, 0);
        for(int i=1;i<=n;i++){
            ps[s[i]]++;
        }
        for(ll i=1;i<=s[n];i++) ps[i] += ps[i-1];

        ll sum = 0, cur = 0;

        ll oldd = -1, oldc = -1;
        for(ll i=1;i<=s[n];i++){
            ll c = s[n]/i;
            ll d = s[n]/i + (s[n] % i ? 1 : 0);
            if(c == oldc && d == oldd){
                sum = (sum + (cur * i)) % MOD;
            }else{
                cur = 0;
                if(c == d){//optimize too
                    for(ll j=1;c*j <= s[n];j++){
                        if(ps[c*j] != ps[c*j-1]) cur++;
                    }
                }else{//optimize
                    cur = 0;
                    for(ll j=1;;j++){
                        ll lo = c*j, hi = d*j;
                        if(hi >= s[n] || hi >= (lo+c)){
                            cur += ps[s[n]] - ps[lo-1];
                            break;
                        }else cur += ps[hi] - ps[lo-1];
                    }
                }
                sum = (sum + (cur * i)) % MOD;
            }
            oldc = c, oldd = d;
        }
        cout << sum << "\n";
    }
}
