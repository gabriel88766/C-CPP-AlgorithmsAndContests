#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll M;

typedef vector<vector<ll>> vvl;
vvl multMatrix(vvl a, vvl b, ll m = M){
    int size = a.size();
    vvl ans(size, vector<ll>(size));
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

vvl binpow(vvl a, ll b, ll  m = M){
    int size = a.size();
    vvl ans(size, vector<ll>(size)); //idt
    for(int i=0;i<size;i++) ans[i][i] = 1; //idt
    while(b > 0){
        if(b & 1) 
            ans = multMatrix(ans, a, m);
        a = multMatrix(a, a, m);
        b >>= 1;
    }
    return ans;
}
const ll auxMax = 1e9;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll A, X;
    cin >> A >> X >> M;
    if(M == 1){
        cout << 0;
        return 0;
    }else if(X == 1){
        cout << 1;
        return 0;
    }
    vvl v = {{(A+1)%M, M - A%M}, {1%M, 0}};
    v = binpow(v, X-2);
    ll ans = (v[0][0]*(A+1) + v[0][1]) % M;
    cout << ans;
}
