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
        ll n, aux;
        cin >> n;
        aux = n;
        vector<pair<ll,ll>> facts;
        for(ll i=2;(i * i) <= aux;i++){
            ll cnt = 0;
            if(!(aux % i)){
                while(!(aux % i)){
                    aux /= i;
                    cnt++;
                }
                facts.push_back({i, cnt});
            }
        }
        if(aux != 1) facts.push_back({aux, 1});
        sort(facts.begin(), facts.end(), greater<pair<ll,ll>>());
        ll ans = 0;
        while(true){
            int ind = -1;
            ll exp = 100, cur = 1;
            for(int i=0;i<facts.size();i++){
                if(facts[i].second != 0){
                    ind = i;
                    exp = min(exp, facts[i].second);
                }
            }
            if(ind == -1) break;
            for(int i=0;i<facts.size();i++){
                if(facts[i].second >= exp){
                    cur *= facts[i].first;
                    facts[i].second -= exp;
                }
            }
            ans += exp * cur;
        }
        
        cout << ans << "\n";

    }
}
