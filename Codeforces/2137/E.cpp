#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


void nxtstep(vector<int> &v){
    int n = v.size();
    vector<int> cnt(n+1);
    for(auto x : v) cnt[x]++;
    int mx = 0;
    while(cnt[mx]) mx++;
    //if x < mx && cnt[x] == 1, then x
    //if x < mx && cnt[x] > 1, then mx
    //if x > mx then mx
    for(auto &x : v){
        if(x < mx){
            if(cnt[x] > 1) x = mx;
        }else x = mx;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        if(k <= 10){
            for(int j=0;j<k;j++) nxtstep(v);
            ll ans = 0;
            for(auto x : v) ans += x;
            cout << ans << "\n";
        }else{
            nxtstep(v);
            nxtstep(v);
            nxtstep(v);
            if(k % 2 == 0) nxtstep(v);
            ll ans = 0;
            for(auto x : v) ans += x;
            cout << ans << "\n";
        }
    }
}
