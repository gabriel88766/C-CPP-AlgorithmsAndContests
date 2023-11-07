
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
        int m;
        cin >> m;
        vector<vector<ll>> v(m);
        vector<vector<ll>> c(m);
        vector<ll> num(m);
        vector<pair<ll,ll>> vp(m);
        map<ll, vector<pair<ll,ll>>> mp;
        ll lg = 0, rg = 0;
        for(int i=0;i<m;i++){
            cin >> num[i] >> vp[i].first >> vp[i].second;
            lg += vp[i].first;
            rg += vp[i].second;
            for(int j=0;j<num[i];j++){
                ll aux;
                cin >> aux;
                v[i].push_back(aux);
            }
            for(int j=0;j<num[i];j++){
                ll aux;
                cin >> aux;
                mp[v[i][j]].push_back({i, aux});
            }
        }
        ll ans = INF_LL;
        cout << lg << " " << rg << " ";
        for(ll i = lg; i <= rg; i++){
            if(!mp.count(i)){
                ans = 0;
                break;
            }else{
                auto v = mp[i];
                ll llo = 0, lss = 0;
                for(auto x : v){
                    cout << x.first << " " << x.second << " ";
                    ll qt = max(vp[x.first].first - (num[x.first] - x.second), 0LL);
                    llo += qt;
                    lss += x.second - qt;
                }
                cout << llo << " " << lss << " ";
                if((rg - lss) < i) llo += i - (rg - lss);
                ans = min(ans, llo);
            }
        }
        cout << ans << "\n";
        
        
    }
}
