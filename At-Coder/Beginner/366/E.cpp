#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll psx[N], psy[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, d;
    cin >> n >> d;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> v){
        return u.first < v.first;
    });
    int mx = vp[n/2].first;
    sort(vp.begin(), vp.end(), [&](pair<int,int> u, pair<int,int> v){
        return u.second < v.second;
    });
    int my = vp[n/2].second;
    vector<int> vsx;
    for(int i = mx; ; i++){
        ll sn = 0;
        for(int j=0;j<n;j++){
            sn += abs(vp[j].first - i);
        }
        if(sn <= d) vsx.push_back(sn);
        else break;
    }
    for(int i=mx-1;;i--){
        ll sn = 0;
        for(int j=0;j<n;j++){
            sn += abs(vp[j].first - i);
        }
        if(sn <= d) vsx.push_back(sn);
        else break;
    }
    for(int i=my; ; i++){
        ll sn = 0;
        for(int j=0;j<n;j++){
            sn += abs(vp[j].second - i);
        }
        if(sn <= d) psy[sn]++;
        else break;
    }
    for(int i=my-1; ; i--){
        ll sn = 0;
        for(int j=0;j<n;j++){
            sn += abs(vp[j].second - i);
        }
        if(sn <= d) psy[sn]++;
        else break;
    }
    for(int i=1;i<=1e6;i++) psy[i] += psy[i-1];
    ll ans = 0;
    for(auto x : vsx){
        ans += psy[d-x];
    }
    cout << ans << "\n";

}
