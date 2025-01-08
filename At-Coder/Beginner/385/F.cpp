#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-13, EP2 = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    long double ans = 0;
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    pair<ll, ll> ar = {0, 15};
    bool ok = true;
    for(int i=0;i<n;i++){
        pair<ll, ll> nar = {vp[i].second, vp[i].first};
        if(nar.first * ar.second <= nar.second * ar.first) ok = false;
        else ar = nar;
    }
    if(ok){
        cout << "-1\n";
        return 0;
    }
    pair<long double, long double> arg;
    int idx = 0;
    arg = {vp[0].second, vp[0].first};
    auto compare = [&](pair<long double, long double> arg1, pair<long double, long double> arg2){
        long double a1 = arg1.first * arg2.second;
        long double a2 = arg1.second * arg2.first;
        return a1 < a2;
    };
    
    for(int i=1;i<n;i++){
        pair<long double, long double> narg = {vp[i].second - ans, vp[i].first};
        if(compare(narg, arg)){
            arg = {vp[i].second - vp[idx].second, vp[i].first - vp[idx].first};
            idx = i;
            // vp[idx].second - x, vp[idx].first = arg
            long double x = arg.first * vp[idx].first / arg.second;
            x -= vp[idx].second;
            ans = -x;
        }else{
            arg = narg; 
            idx = i;
        }
    }


    cout << fixed << setprecision(15) << ans << "\n";
}
