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
    int n;
    ll m;
    cin >> n >> m;
    vector<pair<ll,ll>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    double lo = 0, hi = 1e9+2, mid;
    while((hi - lo)/lo >= EPS){
        double tank = mid = (lo+hi)/2;
        bool ok = true;
        for(int i=0;i<n;i++){
            tank -= (m+tank)/vp[i].first;
            if(tank < 0){
                ok = false; break;
            }
            tank -= (m+tank)/vp[(i+1)%n].second;
            if(tank < 0){
                ok = false; break;
            }
        }
        if(ok) hi = mid;
        else lo = mid;
    }
    if(lo > 1e9) cout << "-1\n";
    else cout << fixed << setprecision(6) << lo;
}
