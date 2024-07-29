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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<pair<ll, ll>> vp(n);
    for(int i=0;i<n;i++) cin >> vp[i].first;
    for(int i=0;i<n;i++) cin >> vp[i].second;

    sort(vp.begin(), vp.end(), [&](pair<ll, ll> &a, pair<ll, ll> &b){
        return a.first > b.first;
    });
    int ans = 0, p = 0;
    ll sum = 0;
    while(p < n && sum <= x){
        sum += vp[p].first;
        p++;
    }
    ans = p;
    p = 0;
    sum = 0;
    sort(vp.begin(), vp.end(), [&](pair<ll, ll> &a, pair<ll, ll> &b){
        return a.second > b.second;
    });
    while(p < n && sum <= y){
        sum += vp[p].second;
        p++;
    }
    ans = min(ans, p);
    cout << ans << "\n";

}
