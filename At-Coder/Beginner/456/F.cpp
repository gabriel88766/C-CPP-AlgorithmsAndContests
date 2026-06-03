#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll s0l[N], s1l[N], s0r[N], s1r[N], dp[N][2];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int k, n;
        cin >> n >> k;
        vector<ll> a(n+2), ps(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) ps[i] = ps[i-1] + a[i];
        vector<ll> vans;
        vector<tuple<int, int, int>> qr;
        for(int i=k;i<=k+2;i++){
            for(int j=i;j<=n;j++){
                ll cur = ps[j] - ps[j - i];
                if(j - 1 >= j - i + 2) qr.push_back({j - i + 2, j - 1, vans.size()});
                vans.push_back(cur);
            }
        }
        function<void(int, int, vector<tuple<int, int, int>>)> solve = [&](int l, int r, vector<tuple<int, int, int>> qr){
            int m = (l + r)/2;
            vector<tuple<int, int, int>> vl, vr;
            for(int i=m;i>=l;i--){
                if(i == m){
                    dp[i][0] = 0;
                    dp[i][1] = a[i];
                }else{
                    dp[i][1] = dp[i+1][0] + a[i];
                    dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
                }
                s0l[i] = max(dp[i][0], dp[i][1]);
            }
            s1l[m] = 0;
            for(int i=m-1;i>=l;i--){
                if(i == m-1){
                    dp[i][0] = 0;
                    dp[i][1] = a[i];
                }else{
                    dp[i][1] = dp[i+1][0] + a[i];
                    dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
                }
                s1l[i] = max(dp[i][0], dp[i][1]);
            }
            for(int i=m+1;i<=r;i++){
                if(i == m+1){
                    dp[i][0] = 0;
                    dp[i][1] = a[i];
                }else{
                    dp[i][1] = dp[i-1][0] + a[i];
                    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                }
                s0r[i] = max(dp[i][0], dp[i][1]);
            }
            s1r[m+1] = 0;
            for(int i=m+2;i<=r;i++){
                if(i == m+2){
                    dp[i][0] = 0;
                    dp[i][1] = a[i];
                }else{
                    dp[i][1] = dp[i-1][0] + a[i];
                    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
                }
                s1r[i] = max(dp[i][0], dp[i][1]);
            }

            for(auto [cl, cr, j] : qr){
                if(cr < m) vl.push_back({cl, cr, j});
                else if(cl > m) vr.push_back({cl, cr, j});
                else{
                    //solve:
                    if(cr == m) vans[j] -= s0l[cl];
                    else{
                        vans[j] -= max(s0l[cl] + s1r[cr], s1l[cl] + s0r[cr]);
                    }
                }
            }
            if(vl.size()) solve(l, m-1, vl);
            if(vr.size()) solve(m+1, r, vr);
        };
        solve(1, n, qr);
        cout << *min_element(vans.begin(), vans.end()) << "\n";
    }
}
