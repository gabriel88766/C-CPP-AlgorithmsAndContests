#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 505;
ll w[20002], v[20002];
ll ans[200005];

ll b1[20002][505], b2[20002][505];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    cin >> q;
    vector<tuple<int, int, int, int>> vx;
    for(int i=1;i<=q;i++){
        int l, r, c;
        cin >> l >> r >> c;
        vx.push_back({l, r, c, i});
    }
    function<void(int, int, vector<tuple<int,int,int,int>>)> solve = [&](int l, int r, vector<tuple<int, int, int, int>> vx){
        int m = (l + r) / 2;
        if(l == r){
            for(auto [a, b, c, j] : vx){
                if(c >= w[l]){
                    ans[j] = v[l];
                }else{
                    ans[j] = 0;
                }
            }
            return;
        }
        for(int i=0;i<=500;i++){
            b2[m][i] = 0;
            b1[m+1][i] = 0;
        }
        for(int i=m+1;i<=r;i++){
            for(int j=500;j>=0;j--){
                if(j >= w[i]) b2[i][j] = max(b2[i-1][j], b2[i-1][j-w[i]] + v[i]);
                else b2[i][j] = b2[i-1][j];
            }
        }
        for(int i=m;i>=l;i--){
            for(int j=500;j>=0;j--){
                if(j >= w[i]) b1[i][j] = max(b1[i+1][j], b1[i+1][j-w[i]] + v[i]);
                else b1[i][j] = b1[i+1][j];
            }
        }
        vector<tuple<int, int, int, int>> vl, vr;
        for(auto [a, b, c, j] : vx){
            if(b <= m) vl.push_back({a, b, c, j});
            else if(a >= m+1) vr.push_back({a, b, c, j});
            else{
                ans[j] = 0;
                for(int u=0;u<=c;u++){
                    ans[j] = max(ans[j], b1[a][u] + b2[b][c-u]);
                }
            }
        }
        solve(l, m, vl);
        solve(m+1, r, vr);
    };
    solve(1, n, vx);
    for(int i=1;i<=q;i++){
        cout << ans[i] << "\n";
    }
}
