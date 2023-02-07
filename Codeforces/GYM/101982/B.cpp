#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+1;
ll mi[N], p[N];
void mobius(){
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    mobius();
    int a,b,c,d;
    ll ans;
    cin >> a >> b >> c >> d;
    ans = (ll)(b-a+1) * (d-c+1);
    int minbd = min(b,d);
    for(int i=2;i<=minbd;i++){
        ll f = mi[i] * (b/i - (a-1)/i) * (d/i-(c-1)/i);
        ans += f;
    }
    cout << ans;// + sum;
}
