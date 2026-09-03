#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[900];
ll ndp[900];

int d2 = -1;
int idx(int i, int j){
    return i*d2 + j;
}

inline  void cp(ll *dp1, ll *dp2, int s1, int s2){
    for(int i=0;i<=s1;i++){
        for(int j=0;j<=s2;j++){
            dp1[idx(i, j)] = dp2[idx(i, j)];
        }
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
        int n, x;
        cin >> n >> x;
        map<int, vector<int>> mp;
        map<int, int> mpx;
        int ax = x;
        for(int j = 2; j * j <= ax; j++){
            if(ax % j == 0){
                int cnt = 0;
                while(ax % j == 0){
                    ax /= j;
                    cnt++;
                }
                mpx[j] = cnt;
            }
        }
        if(ax != 1) mpx[ax] = 1;
        //init empty all prime factors of x;
        for(auto [k, v] : mpx) mp[k] = {};
        for(int i=0;i<n;i++){
            int cx;
            cin >> cx;
            for(int j=2;j*j <= cx; j++){
                if(cx % j == 0){
                    int cnt = 0;
                    while(cx % j == 0){
                        cx /= j;
                        cnt++;
                    }
                    mp[j].push_back(cnt);
                }
            }
            if(cx != 1) mp[cx].push_back(1);
        }
        ll ans = 1;
        for(auto [k, vec] : mp){
            int nd = mpx.count(k) ? mpx[k] : 0;
            if(vec.size() == 0){
                ans = 0;
                break;
            }
            int mx = *max_element(vec.begin(), vec.end());
            d2 = mx+1;
            for(int i=0;i<=mx+nd;i++) for(int j=0;j<=mx;j++) dp[idx(i, j)] = 0;
            
            dp[idx(0, 0)] = 1;
            for(auto xv : vec){
                cp(ndp, dp, mx+nd, mx);
                for(int i=0;i<=mx+nd;i++){
                    for(int j=0;j<=mx;j++){
                        if(dp[idx(i, j)] == 0) continue;
                        for(int u=1;u <= xv && u + i <= mx + nd;u++){
                            int ni = i + u;
                            int nj = max(j, u);
                            ndp[idx(ni, nj)] = (ndp[idx(ni, nj)] + dp[idx(i, j)]) % MOD;
                        }
                    }
                }
                cp(dp, ndp, mx+nd, mx);
            }
            ll tt = 0;
            for(int j = 0; j <= mx; j++) tt = (tt + dp[idx(nd + j, j)]) % MOD;
            ans *= tt;
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
