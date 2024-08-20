#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool dp[41][41][41][41];
int par[41][41][41][41];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        memset(par, 0, sizeof(par));
        int n, A, B;
        cin >> n >> A >> B;
        vector<int> pa(41), pb(41);
        pa[0] = A == 1 ? 0 : 1;
        pb[0] = B == 1 ? 0 : 1;
        for(int i=1;i<=40;i++){
            pa[i] = (10 * pa[i-1]) % A;
            pb[i] = (10 * pb[i-1]) % B;
        }
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        s = " " + s;
        dp[0][0][0][0] = true;
        for(int i=1;i<=n;i++){
            int d = s[i] - '0';
            for(int r=0;r<i;r++){
                int bb = i-1 - r;
                for(int a=0;a<A;a++){
                    for(int b=0;b<B;b++){
                        if(dp[i-1][r][a][b]){
                            int ca = (a + d*pa[r]) % A;
                            int cb = (b + d*pb[bb]) % B;
                            dp[i][r][a][cb] = true;
                            dp[i][r+1][ca][b] = true;
                            par[i][r][a][cb] = (i-1) + 41*r + 41*41*a + 41*41*41*b;
                            par[i][r+1][ca][b] = (i-1) + 41*r + 41*41*a + 41*41*41*b;
                        }
                    }
                }
            }
        }
        int br = -1;
        for(int r=1;r<n;r++){
            if(dp[n][r][0][0]){
                if(abs(2*br - n) > abs(2*r - n)){
                    br = r;
                }
            }
        }
        string ans = "";
        tuple<int,int,int,int> cur = {n, br, 0, 0};
        if(br == -1) cout << "-1\n";
        else{
            for(int i=0;i<n;i++){
                auto [j, r, a, b] = cur;
                int xx = par[j][r][a][b];
                int nj = xx % 41;
                xx /= 41;
                int nr = xx % 41;
                xx /= 41;
                int na = xx % 41;
                xx /= 41;
                int nb = xx % 41;
                if(nr == r) ans += "B";
                else ans += "R";
                cur = {nj, nr, na, nb};
            }
            cout << ans << "\n";
        }
        


    }
}
