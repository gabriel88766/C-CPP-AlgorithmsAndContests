#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
// ll ndmx[N], ndmn[N], cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> val;
        ll inis = 0;
        for(int i=1;i<=n;i++){
            ll x;
            cin >> x;
            inis += x;
            val.push_back(x);
        }
        int mn = *min_element(val.begin(), val.end());
        int mx = *max_element(val.begin(), val.end());
        sort(val.begin(), val.end());
        int lo = mn, hi = mx;
        while(lo != hi){
            int mid = lo + (hi - lo + 1)/2;
            //all below mid will be mid.
            ll tt = 0;
            for(auto &x : val) tt += max(0LL, mid - x);
            for(auto &x : val) tt -= max(0LL, x - (mid + k));
            if(tt <= 0) lo = mid;
            else hi = mid - 1;
        }
        ll tt = 0;
        for(auto &x : val){
            if(x < lo){
                tt += lo - x;
                x = lo;
            }
        }
        ll att = tt;
        ll ans = 0;
        ans += tt*k;
        for(int i=n-1;i>=0;i--){
            if((val[i] - val[i-1]) * (n - i) >= att){
                //make all val[i] - rx;
                ll rx = att / (n-i);
                rx = val[i] - rx;
                for(int j=n-1;j>=i;j--){
                    tt -= (val[j] - rx);
                    val[j] = rx;
                }
                assert(tt <= (n-i));
                for(int j=i;j<=n-1;j++){
                    if(tt){
                        val[j]--;
                        tt--;
                    }else break;
                }
                break;
            }else att -= (val[i] - val[i-1]) * (n - i);
        }
        multiset<ll> ms;
        ll es = 0;
        for(auto &x : val) es += x;
        assert(es == inis);
        for(auto &x : val) ms.insert(x);
        while(true){
            int ini = *ms.begin();
            int ed = *prev(ms.end());
            if(ed - ini >= k + 1){
                ms.erase(prev(ms.end()));
                ms.insert(ed-1);
                ms.erase(ms.begin());
                ms.insert(ini+1);
                ans += k;
            }else break;
        }

        
        for(auto x : ms){
            ans += (x*(x+1))/2;
        }
        cout << ans << "\n";
    }   
}
