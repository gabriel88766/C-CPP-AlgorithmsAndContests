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
    vector<pair<int,int>> vp(n);
    ll dd = 0;
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
        dd += vp[i].first;
    }
    double lo = 0, hi = 1e8;
    while((hi - lo)/lo > EPS){
        double mid = (lo + hi)/2;
        double dl = 0, dr = 0;
        double tl = mid;
        for(int i=0;i<n;i++){
            double ttb = vp[i].first;
            ttb /= vp[i].second;
            if(tl >= ttb){
                tl -= ttb;
                dl += vp[i].first;
            }else{
                dl += (tl/ttb) * vp[i].first;
                break;
            }
        }
        tl = mid;
        for(int i=n-1;i>=0;i--){
            double ttb = vp[i].first;
            ttb /= vp[i].second;
            if(tl >= ttb){
                tl -= ttb;
                dr += vp[i].first;
            }else{
                dr += (tl/ttb) * vp[i].first;
                break;
            }
        }
        if(dl + dr >= dd) hi = mid;
        else lo = mid;
    }
    double ans = 0;
    for(int i=0;i<n;i++){
        double ttb = vp[i].first;
        ttb /= vp[i].second;
        if(lo >= ttb){
            lo -= ttb;
            ans += vp[i].first;
        }else{
            ans += (lo/ttb) * vp[i].first;
            break;
        }
    }
    cout << setprecision(10) << ans << "\n";
}
