#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool cmp(pair<ll,ll> u, pair<ll,ll> v){
    if(u.first != v.first) return u.first < v.first;
    else return u.second > v.second;
}

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
        vector<pair<ll, ll>> vp(n);
        vector<int> cnt(n+1,0);
        for(int i=0;i<n;i++){
            cin >> vp[i].first >> vp[i].second;
        }
        sort(vp.begin(), vp.end(), cmp);
        ll ans = 0;
        for(int i=0;i<n;i++){
            if(cnt[vp[i].first] < vp[i].first){
                ans += vp[i].second;
                cnt[vp[i].first]++;
            }
        }
        cout << ans << "\n";
    }
}
