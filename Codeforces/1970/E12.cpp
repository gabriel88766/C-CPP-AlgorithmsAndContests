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
    vector<vector<ll>> mat(m, vector<ll>(m));
    vector<int> l(m), s(m);
    for(int i=0;i<m;i++) cin >> s[i];
    for(int i=0;i<m;i++) cin >> l[i];
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            mat[i][j] = s[i] * s[j] + s[i] * l[j] + s[j] * l[i];
        }
    }
    mat = binpow(mat, n);
    ll ans = 0;
    for(int i=0;i<m;i++) ans += mat[0][i];
    ans %= MOD;
    cout << ans << "\n";
}
