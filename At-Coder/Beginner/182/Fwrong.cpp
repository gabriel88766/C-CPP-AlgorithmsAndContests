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
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll neg = 0, pos = 1;
    ll oneg = 0, opos = 0;
    for(int i=1;i<n;i++){
        ll nneg = 0, npos = 0;
        ll nd = x % v[i];
        ll v1 = ((oneg % v[i]) + v[i]) % v[i];
        ll v2 = ((opos % v[i]) + v[i]) % v[i];
        if(v1 == nd){
            nneg = neg;
        }else{
            nneg = neg + pos;
        }
        if(v2 == nd){
            npos = pos;
        }else{
            npos = neg + pos;
        }
        pos = npos;
        neg = nneg;
        opos = x % v[i];
        oneg = (x % v[i]) - v[i];
    }
    cout << pos + neg << "\n";

}
