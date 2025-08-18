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
    int n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), greater<pair<ll, ll>>());
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(w >= vp[i].second){
            ans += vp[i].first * vp[i].second;
            w -= vp[i].second;
        }else{
            ans += w * vp[i].first;
            w = 0;
        }
    }
    cout << ans << "\n";
}
