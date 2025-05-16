#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int basis[32];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        while(x != 0 && basis[31-__builtin_clz(x)]) x ^= basis[31-__builtin_clz(x)];
        if(x != 0) basis[31-__builtin_clz(x)] = x;
    }
    int ans = 1;
    for(int i=29;i>=0;i--){
        if(basis[i]){
            ans *= 2;
        }
    }
    cout << ans << "\n";
}
