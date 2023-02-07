#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
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
        ll n, m1, m2, m;
        cin >> n >> m1 >> m2;
        vector<pair<ll,ll>> pf;
        vector<ll> d;
        for(ll i=2;i<1e5;i++){
            int cnti = 0;
            while(m1 >= i && !(m1 % i)){
                cnti++;
                m1 /= i;
            }
            while(m2 >= i && !(m2 % i)){
                cnti++;
                m2 /= i;
            }
            if(cnti) pf.push_back({i, cnti});
        }
        if(m1 != m2){
            if(m1 > 1) pf.push_back({m1, 1}); 
            if(m2 > 1) pf.push_back({m2,1});
        }else if(m1 != 1) pf.push_back({m1, 2});
        
        d.push_back(1);
        for(int i=0;i<pf.size();i++){
            vector<ll> curd = d;
            ll fact = 1;
            for(int j=1;j<=pf[i].second;j++){
                fact *= pf[i].first;
                for(int k = 0; k<d.size();k++){
                    curd.push_back(fact * d[k]);
                }
            }
            d = curd;
        }
        sort(d.begin(), d.end());
        vector<ll> a;

        int ind1 = 0;
        while(d[ind1] <= n){
            a.push_back(1);
            ind1++;
        }
        auto it = lower_bound(d.begin(), d.end(), n);
        for(int i=ind1;i<d.size();i++){
            int ind = it - d.begin();
            if(d[ind] > n) ind--;
            for(int j = ind; j >= 0; j--){
                if(!(d[i] % d[j])){
                    if(d[i]/d[j] <= n) a.push_back(d[i]/d[j]);
                    break;
                }
            }
        }
        

        ll ans = 0;
        for(int i=0;i<a.size();i++) ans ^= a[i];
        cout << a.size() << " " << ans << "\n";

        
    }
}
