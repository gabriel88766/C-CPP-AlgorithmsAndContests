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
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    int sqt = sqrt(v[0])+1;
    vector<int> chk;
    for(int i=1;i<=sqt;i++){
        if((v[0]/i)*(i+1) >= v[0]) chk.push_back(i);
    }
    int cur = sqt + 1;
    while(cur <= v[0]){
        ll d = v[0] / cur;
        ll lo = cur, hi = v[0];
        while(lo != hi){
            ll mid = lo + (hi - lo + 1) / 2;
            if(d * mid >= v[0]) hi = mid - 1;
            else lo = mid;
        }
        for(int i=lo;i<=min(lo+1, (ll)v[0]);i++){
            if((v[0]/i)*(i+1) >= v[0]) chk.push_back(i);
        }
        cur = lo + 2;
    }
    ll ans = INF_LL;
    for(auto x : chk){
        ll curs = 0;
        for(int i=0;i<n;i++){
            if((v[i]/x)*(x+1) >= v[i]){
                curs += (v[i]+x)/(x+1);
            }else{
                curs = INF_LL;
                break;
            }
        }
        ans = min(ans, curs);
    }
    cout << ans << "\n";
}
