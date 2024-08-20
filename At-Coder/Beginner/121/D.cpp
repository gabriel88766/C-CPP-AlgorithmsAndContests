#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    ll tto = (B+1)/2 - A/2;
    if(tto % 2) ans = 1;
    for(int i=1;i<=50;i++){
        ll p1 = 1LL << i;
        ll p2 = 1LL << (i+1);
        if(A/p2 != B/p2){
            ll cb = B % p2;
            ll ca = A % p2;
            ll aux = 0;
            if(ca <= p1) aux += p1;
            else aux += 2*p1 - ca;
            if(cb >= p1) aux += cb - p1 + 1;
            if(aux % 2) ans |= p1;
        }else{
            ll cb = B % p2;
            ll ca = A % p2;
            if(cb < p1) continue;
            else if(ca >= p1){
                if((cb-ca+1)%2) ans |= p1;
            }else{
                if((cb - p1 + 1) % 2) ans |= p1;
            }
        }
    }
    cout << ans << "\n";
}
