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
    ll n;
    cin >> n;
    set<pair<ll,ll>> gr, lo, ot;
    vector<pair<ll,ll>> vp;
    ll ans, sum1 = 0, sum2 = 0;
    for(ll i=1;i<=n;i++){
        ll aux;
        cin >> aux;
        gr.insert({aux, i});
        sum1 += aux;
    }
    for(ll i=1;i<=n;i++){
        ll aux;
        cin >> aux;
        vp.push_back({aux, i+n});
        lo.insert({aux, i+n});
    }
    for(ll i=1;i<=n;i++){
        ll aux;
        cin >> aux;
        lo.insert({aux, i+2*n});
    }
    vector<pair<ll,ll>> rmlist;
    int cnt = 0;
    for(auto it = lo.begin(); it!= lo.end(); ++it){
        ++ cnt;
        if(cnt > n) {rmlist.push_back(*it); ot.insert(*it);}
        else sum2 += it->first;
    }
    for(auto x : rmlist) lo.erase(x);
    ans = sum1 - sum2;
    for(int i=0;i<n;i++){
        if(lo.count(vp[i])){
            sum2 -= vp[i].first;
            lo.erase(vp[i]);
            sum2 += ot.begin()->first;
            lo.insert(*ot.begin());
            ot.erase(ot.begin());
        }else ot.erase(vp[i]);
        if(vp[i].first > gr.begin()->first){
            sum1 -= gr.begin()->first;
            sum1 += vp[i].first;
            gr.erase(gr.begin());
            gr.insert(vp[i]);
        }
        ans = max(ans, sum1 - sum2);
    }
    cout << ans;
}
