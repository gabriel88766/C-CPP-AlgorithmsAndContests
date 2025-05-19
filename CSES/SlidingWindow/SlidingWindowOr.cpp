#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int v[20000001];
int ans[10000001];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    int p = 1;
    v[0] = x;
    while(p < n){
        x = a*x + b;
        x %= c;
        v[p++] = x;
    }
    for(int j=0;j<=23;j++){
        if(k < 2*(1 << j)){
            for(int i=0;i<n;i++) ans[i] = v[i] | v[i+k - (1 << j)];
            break;
        }
        for(int i=0;i<n;i++){
            v[i] |= (v[i + (1 << j)]);
        }
    }
    int rans = 0;
    for(int i=0;i<n-k+1;i++){
        rans ^= ans[i];
    }
        
    cout << rans << "\n";
}
