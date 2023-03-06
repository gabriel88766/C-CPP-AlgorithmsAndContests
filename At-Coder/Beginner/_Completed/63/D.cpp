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
    //freopen("in", "r", stdin); //test input
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    ll lo = 1, hi = 1e9+1, mid;
    while(lo != hi){
        ll cnt = 0;
        mid = (lo+hi)/2;
        ll dmgb = b*mid;
        for(int i=0;i<n;i++){
            if(dmgb >= v[i]) continue;
            cnt += (v[i]-dmgb)/(a-b);
            if((v[i]-dmgb) % (a-b)) cnt++;
        }
        if(cnt <= mid) hi = mid;
        else lo = mid +1;
    }
    cout << lo;
}
