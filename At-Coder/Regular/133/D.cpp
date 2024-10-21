#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll vx;
ll solve(ll i, ll j, ll l = 0, ll r = ((1LL) << 60) - 1){
    if(l > j || r < i) return 0;
    ll m = (l + r)/2;
    ll mxc = (vx ^ l) | (r ^ l);
    ll mnc = (vx ^ l) & ~(r ^ l);
    if(mnc >= i && mxc <= j && l >= i && r <= j) return r - l + 1;
    else if(mxc < i || mnc > j) return 0;
    return solve(i, j, l, m) + solve(i, j, m+1, r);
}

int m1[] = {0, 0, 1, 3}, m2[] = {0, 1, 3, 0};
bool s1[] = {0, 1, 0, 1}, s2[] = {1, 0, 1, 0};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll l, r, v;
    cin >> l >> r >> v;
    __int128 ans = 0;
    ll aux = (v/4) * 4;
    ll aux2 = aux / 4;
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            if((m1[j] ^ m2[k]) == v % 4){
                //solve...
                if(s1[j] && s2[k]){
                    ll nl, nr;
                    nl = (l/4)*4 + j;
                    if(nl < l) nl += 4;
                    nr = (r/4)*4 + k;
                    if(nr > r) nr -= 4;
                    nl = (nl/4);
                    nr = (nr/4);
                    vx = aux2;
                    if(aux){
                        if(nr >= nl) ans += solve(nl, nr)/2;
                    }else{
                        if(k >= j) ans += solve(nl, nr);
                    }
                }else if(s1[j]){
                    //So aux = num
                    ll fn = aux + k;
                    if(fn < aux+j) fn += 4;
                    ll ln = (r/4) * 4 + k;
                    if(ln > r) ln -= 4;
                    if(ln >= fn && aux + j >= l){ 
                        __int128 ttf = 0;
                        ttf = ((ln - fn)/4 + 1);
                        ans += ttf;
                    }
                }else if(s2[k]){
                    ll fn = (l/4) * 4 + j;
                    if(fn < l) fn += 4;
                    ll ln = aux + j;
                    if(ln > aux + k) ln -= 4;
                    if(ln >= fn && aux + k <= r){
                        __int128 ttf = 0;
                        ttf = ((ln - fn)/4 + 1);
                        ans += ttf;
                    }
                }else{
                    if(v/4 == 0){
                        //then ok all pairs
                        __int128 ttf = 0;
                        ll fn = (l/4) * 4 + k;
                        ll fj = (l/4) * 4 + j;
                        if(fj < l) fj += 4;
                        if(fn < l) fn += 4;
                        if(fn < fj) fn += 4;
                        ll ln = (r/4) * 4 + k;
                        if(ln > r) ln -= 4;
                        ttf = ((ln - fn)/4 + 1);
                        ans += ((ttf)*(ttf+1))/2;
                    }//else never
                }
            }
        }
    }
    ll a = ans % MOD;
    cout << a << "\n";
}
