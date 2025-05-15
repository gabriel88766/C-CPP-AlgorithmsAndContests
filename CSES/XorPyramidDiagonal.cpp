#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int n;
int v[129][N], lw[N];
int solve(int n, int k){
    if(n <= 128) return v[n][k];
    else{
        return solve(n-lw[n], k) ^ solve(n-lw[n], k + lw[n]);
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int gr = 1;
    for(int i=2;i<N;i++){
        if(gr*2 + 1 <= i) gr *= 2;
        lw[i] = gr;
    }
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[1][i];
    }
    for(int i=2;i<=128;i++){
        for(int j=1;j<=n-i+1;j++){
            v[i][j] = v[i-1][j] ^ v[i-1][j+1];
        }
    }
    for(int i=1;i<=n;i++){
        cout << solve(i, 1) << " ";
    }
    cout << "\n";
}
