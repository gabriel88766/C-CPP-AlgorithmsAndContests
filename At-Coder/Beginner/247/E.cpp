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
    ll ans = 0;
    vector<ll> cv;
    auto solve = [&](vector<ll> &cv){
        if(cv.size() == 0) return 0LL;
        int n = cv.size();
        vector<int> v1, v2;
        for(int i=0;i<cv.size();i++){
            if(cv[i] == x) v1.push_back(i);
            if(cv[i] == y) v2.push_back(i);
        }
        int p1 = 0, p2 = 0;
        ll cb = 0;
        ll ans = 0;
        while(p1 < v1.size() && p2 < v2.size()){
            ll mn = min(v1[p1], v2[p2]);
            ll mx = max(v1[p1], v2[p2]);
            ans += (mn - cb + 1) * (n - mx);
            if(mn == v1[p1]){
                cb = v1[p1] + 1;
                p1++;
            }else{
                cb = v2[p2] + 1;
                p2++;
            }
        }
        return ans;
    };
    for(int i=1;i<=n;i++){
        int xx;
        cin >> xx;
        if(xx <= x && xx >= y) cv.push_back(xx);
        else{
            ans += solve(cv);
            cv.clear();
        } 
    }
    ans += solve(cv);
    cout << ans << "\n";
}
