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
    ll n, a, b;
    cin >> n >> a >> b;
    ll p, q, r, s;
    cin >> p >> q >> r >> s;
    for(ll i = p;i<=q;i++){
        for(ll j=r;j<=s;j++){
            ll k = i - a;
            bool bl = false;
            if(j == b + k){
                if(max(1-a,1-b) <= k && k <= min(n-a, n-b)) bl = true;
            }
            if(j == b - k){
                if(max(1-a,b-n) <= k && k <= min(n-a, b-1)) bl = true;
            }
            if(bl) cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
}
