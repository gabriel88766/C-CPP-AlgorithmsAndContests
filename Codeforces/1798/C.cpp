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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(int i=0;i<n;i++){
            cin >> a[i] >> b[i];
        }
        vector<pair<ll, ll>> cond;
        for(int i=0;i<n-1;i++){
            cond.push_back({lcm(b[i], b[i+1]), __gcd(a[i]*b[i], a[i+1]*b[i+1])});
        }
        int ans = 1;
        int bp = 0;
        ll curl = 0, curr = 0;
        while(bp < n-1){
            if(cond[bp].second % cond[bp].first) {
                ans++;
                bp++;
                curl = curr = 0;
            }
            else{
                if(curr){
                    ll lc = lcm(cond[bp].first, curl);
                    ll gc = gcd(curr, cond[bp].second);
                    if(gc % lc){
                        ans++;
                        curl = curr = 0;
                    }else{
                        curl = lc;
                        curr = gc;
                    }
                    bp++;
                }else{
                    curl = cond[bp].first, curr = cond[bp].second;
                    bp++;
                }
            }
        }
        cout << ans << "\n";
    }
}
