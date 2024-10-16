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
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> vp(n);
        for(int i=0;i<n;i++){
            cin >> vp[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> vp[i].second;
        }
        sort(vp.begin(), vp.end());
        multiset<ll> ms; //highest k
        ll ans = 0;
        ll curs = 0;
        for(int i=0;i<n;i++){
            if(vp[i].second <= vp[i].first) continue;
            curs -= vp[i].first;
            if(k){
                if(ms.size() < k) ms.insert(vp[i].second);
                else if(vp[i].second <= *ms.begin()) curs += vp[i].second;
                else{
                    curs += *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(vp[i].second);
                }
            } else curs += vp[i].second;
            ans = max(ans, curs);
        }
        cout << ans << "\n";
    }
}
