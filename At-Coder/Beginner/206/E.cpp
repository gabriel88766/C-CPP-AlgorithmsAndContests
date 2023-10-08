#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
ll mi[N];
int p[N];
void mobius(){
    for(int i=2;i<N;i++) mi[i] = 1;
    for(ll i=2;i<N;i++){
        if(!p[i]){
            for(ll j=i; j< N; j += i){
                p[j] = 1;
                mi[j] *= -1;
            }
            for(ll j=i*i;j<N;j += i*i){
                mi[j] = 0;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    mobius();
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for(ll i=2;i<=r;i++){
        ans -= mi[i] * (r/i - (l-1)/i) * (r/i - (l-1)/i);
    }
    for(ll i=max(l, 2LL); i<= r; i++){
        ans -= 2 * (r/i - (l-1)/i) - 1;
    }
    cout << ans << "\n";
}
