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
    vector<pair<int, int>> vp(n);
    int mnx, mxx, mny, mxy;
    for(int i=0;i<n;i++){
        cin >> vp[i].first >> vp[i].second;
        if(i == 0){
            mnx = mxx = vp[i].first;
            mny = mxy = vp[i].second;
        }else{
            mnx = min(mnx, vp[i].first);
            mxx = max(mxx, vp[i].first);
            mny = min(mny, vp[i].second);
            mxy = max(mxy, vp[i].second);
        }
    }
    int ans = max((mxx - mnx + 1)/2, (mxy - mny + 1)/2);
    cout << ans << "\n";
}
