#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll mxall = 0;
ll collatz(ll x){
    ll cnt = 0;
    while(x != 1){
        if(x % 2){
            x = 3*x+1;
            cnt++;
        }else{
            x /= 2;
            cnt++;
        }
    }
    return cnt;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll x;
    cin >> x;
    if(x == 4 || x == 2 || x == 1) cout << 4 << "\n";
    else cout << collatz(x) + 2 << "\n";
}
