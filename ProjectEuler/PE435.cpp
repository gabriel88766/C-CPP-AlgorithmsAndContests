#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll nMOD = 15LL*14*13*12*11*10*9*8*7*6*5*4*3*2*1;
const ll N = 1e15;
const ll M = 100;

vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b, ll m){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + (__int128)a[i][k] * b[k][j]) % m;
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll b, ll  m = nMOD){
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

ll sum_fibo(ll a, ll b, ll n){//x, x^2, n
    //F1 = a, F2 = b, Fn = a*Fn-1 + b*Fn-2
    //Sn = Sn-1 + Fn = Sn-1 + aFn-1 + bFn-2 = (a+1)*Sn-1 + (b-a)*Sn-2 - b*Sn-3
    if(n == 1) return a;
    else if(n == 2) return a + b;
    else if(n == 3) return a + b + 2*a*b; //this is just formalism, never happens
    else{   
        vector<vector<ll>> mat(3, vector<ll>(3));
        mat[0][0] = a+1;
        mat[0][1] = b-a;
        mat[0][2] = nMOD - b;
        mat[1][0] = 1;
        mat[2][1] = 1;
        mat = binpow(mat, n-3);
        ll ans = mat[0][0] * (2*a*b + a + b) + mat[0][1] * (a+b) + mat[0][2] * a;
        return ans % nMOD;
    } 
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll ans = 0;
    for(int i=1;i<=M;i++){
        //recurrence 
        ll A = i;
        ll B = i*i;
        // C = A + B
        ll cur = sum_fibo(A, B, N);
        ans = (ans + cur) % nMOD;
    }
    cout << ans << "\n";
}
