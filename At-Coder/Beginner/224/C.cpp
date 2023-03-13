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
    ll ans = 0;
    int n;
    cin >> n;
    vector<pair<ll,ll>> p(n);
    for(int i=0;i<n;i++) cin >> p[i].first >> p[i].second;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                ans++;
                ll x1 = p[j].first - p[i].first, x2 = p[k].first - p[j].first;
                ll y1 = p[j].second - p[i].second, y2 = p[k].second - p[j].second;
                if(x1*y2 == x2*y1) ans--;
            }
        }
    }
    cout << ans;
}
