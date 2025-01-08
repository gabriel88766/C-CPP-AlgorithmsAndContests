#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b, ll m = MOD){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]) % m;
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll b, ll  m = MOD){
    int size = a.size();
    vector<vector<ll>> ans(size,vector<ll>(size)); //idt
    for(int i=0;i<size;i++) ans[i][i] = 1; //idt

    while(b > 0){
        if(b & 1) 
            ans = multMatrix(ans, a, m);
        a = multMatrix(a, a, m);
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m, n;
    cin >> m >> n;
    --n;
    vector<vector<ll>> mat(2, vector<ll>(2));
    vector<vector<int>> rt(2, vector<int>(m));
    for(int i=0;i<m;i++) cin >> rt[0][i];
    for(int i=0;i<m;i++) cin >> rt[1][i];
    pair<ll, ll> ini = {rt[0][0], rt[1][0]};
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                if(j == 0){
                    //then the first can be small or large
                    mat[k][j] += rt[k][i] * (rt[0][i] + rt[1][i]);
                }else{
                    mat[k][j] += rt[k][i] * rt[0][i];
                }
                mat[k][j] %= MOD;
            }
        }
    }
    mat = binpow(mat, n);
    pair<ll, ll> nowv = {(mat[0][0]*ini.first + mat[0][1]*ini.second) % MOD, (mat[1][0]*ini.first + mat[1][1]*ini.second) % MOD};
    ll ans = 0;
    for(int i=0;i<m;i++){
        ans += nowv.first * (rt[0][i] + rt[1][i]) + nowv.second * rt[0][i];
        ans %= MOD;
    }
    ans %= MOD;
    cout << ans << "\n";
}
