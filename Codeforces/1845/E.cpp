#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct Mint{
    int v;
    Mint(){ v = 0;}
    Mint(int u){ v = (u >= 0 ? u % MOD : u % MOD + MOD);}
    friend Mint operator+ (Mint a, Mint const &b){ return a += b;}
    Mint operator+= (Mint u){ v = (v+u.v >= MOD ? v+u.v-MOD : v+u.v); return *this;}
    friend ostream& operator<<(ostream& os, const Mint& num){
        os << num.v;
        return os;
    }
};

Mint dp[1505][1505];

int pos[1505];
int v[1505];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    dp[0][0] = 1;
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        if(v[i]){
            cnt++;
            pos[cnt] = i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=min(i,cnt);j>=1;j--){
            int tt = abs(pos[j] - i);
            for(int w=tt;w<=k;w++){
                dp[j][w] += dp[j-1][w-tt];
            }
        }
    }
    Mint ans = 0;
    for(int i = k%2; i <= k; i += 2) ans += dp[cnt][i];
    cout  << ans << "\n";
}

//O(n^2 k) is intended, but it still pass!
