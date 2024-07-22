#include <bits/stdc++.h>
#pragma GCC optimize("O2")
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll p10[22];

vector<vector<ll>> mpoly(const vector<vector<ll>> &a, const vector<vector<ll>> &b){//this case a.size() == b.size()
    vector<vector<ll>> ans(24);
    for(int j=0;j<=23;j++) ans[j].resize(23);


    for(int i=0;i<=23;i++){
        for(int j=0;i+j<=23;j++){
            for(int k=0;k<23;k++){
                for(int l=0;l<23;l++){
                    ans[i+j][(k+l)%23] += a[i][k] * b[j][l];
                    ans[i+j][(k+l)%23] %= MOD;
                    
                }
            }
        }
    }
    return ans;
}

vector<vector<ll>> ppoly(vector<vector<ll>> a, ll n){
    vector<vector<ll>> ans(24);
    for(int j=0;j<=23;j++) ans[j].resize(23);
    ans[0][0] = 1;
    while(n){
        if(n & 1) ans = mpoly(ans, a);
        a = mpoly(a, a);
        n >>= 1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll mp = 11LL*11*11*11*11*11*11*11*11*11*11*11;
    cout << mp << " ";
    p10[0] = 1;
    for(int i=1;i<=21;i++){
        p10[i] = (p10[i-1]*10)%23;
    }
    mp--;
    ll tta = mp / 22;
    ll ttm = mp % 22;
    vector<vector<ll>> ans(24, vector<ll>(23)); //x^0 to x^23 (24), 23 from mod
    ans[0][0] = 1;
    for(int i=0;i<=21;i++){
        vector<vector<ll>> cur(24, vector<ll>(23));
        cur[0][0] = 1;
        for(int j=1;j<=9;j++) cur[j][(p10[i] * j) % 23] = 1;
        ll xp = tta + (i <= ttm ? 1 : 0);
        auto x = ppoly(cur, xp);
        ans = mpoly(ans, x);

    }    
    cout << ans[23][0] << "\n";
    
}