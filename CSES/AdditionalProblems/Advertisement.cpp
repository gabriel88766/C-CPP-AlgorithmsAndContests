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
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    stack<pair<ll,ll>> stp;
    ll ans = 0;
    for(int j=1;j<=n;j++){
        if(!stp.empty() && stp.top().first > v[j]){
            ll fi;
            while(!stp.empty() && stp.top().first > v[j]){
                ans = max(ans, stp.top().first * (j-stp.top().second));
                fi = stp.top().second;
                stp.pop();
            }
            stp.push({v[j], fi});
        }else stp.push({v[j], j});
    }
    while(!stp.empty()){
        ans = max(ans, stp.top().first * (n+1-stp.top().second));
        stp.pop();
    }
    cout << ans;
}



