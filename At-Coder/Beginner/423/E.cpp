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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<tuple<int, int, int>> vq;
    vector<ll> ans(q);
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        vq.push_back({a, b, i});
    }
    function<void(vector<tuple<int, int, int>>, int, int)> solve = [&](vector<tuple<int, int, int>> vq, int l, int r){
        if(vq.size() == 0) return;
        if(l == r){
            for(auto [a, b, j] : vq){
                ans[j] = v[a];
            }
            return;
        }
        int m = (l + r) / 2;
        vector<tuple<int, int, int>> vl, vr;
        vector<ll> ps1(r - l + 1), ps2(r - l + 1), ps3(r - l + 1), ps4(r - l + 1);
        for(ll i=m+1;i<=r;i++){
            if(i == m+1){
                ps1[i - l] = v[i];
                ps2[i - l] = v[i];
                ps3[i - l] = v[i];
                ps4[i - l] = v[i];
            }else{
                ps1[i - l] = v[i] + ps1[i-1 - l];
                ps2[i - l] = ps2[i-1 - l] + ps1[i - l];
                ps3[i - l] = ps3[i - 1 - l] + v[i] * (i - m);
                ps4[i - l] = ps4[i - 1 - l] + ps3[i - l];
            }
        }
        for(ll i=m;i>=l;i--){
            if(i == m){
                ps1[i - l] = v[i];
                ps2[i - l] = v[i];
                ps3[i - l] = v[i];
                ps4[i - l] = v[i];
            }else{
                ps1[i - l] = ps1[i+1 - l] + v[i];
                ps2[i - l] = ps2[i+1 - l] + ps1[i - l];
                ps3[i - l] = ps3[i + 1 - l] + v[i] * (m - i + 1);
                ps4[i - l] = ps4[i + 1 - l] + ps3[i - l];
            }
        }
        for(auto [a, b, j] : vq){
            if(b <= m) vl.push_back({a, b, j});
            else if(a >= m+1) vr.push_back({a, b, j});
            else{
                ll sz1 = m - a + 1;
                ll sz2 = b - m;
                ans[j] = sz1 * ps2[b - l] + sz2 * ps2[a - l] + ps4[a - l] + ps4[b - l];
            }
        }
        solve(vl, l, m);
        solve(vr, m+1, r);
    };
    solve(vq, 1, n);
    for(int i=0;i<q;i++) cout << ans[i] << "\n";
    // cout << "\n";
}
