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
    //use a + b = a xor b + 2 * (a and b) 
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=3;i<n;i++) v[2] = v[2] ^ v[i];
    ll a = v[0], b = v[1], c = v[2];
    ll ans = 0;
    ll S = a + b;
    if(S >= c && (S - c) % 2 == 0){
        //the only way to go!
        ll x = (S-c) / 2; //this must be the and
        ll y = x;
        if(x <= a){
            //Now I can set more bits.
            bool ok = true;
            for(int j=50;j>=0;j--){
                if(x & (1LL << j)){
                    if(c & (1LL << j)){ //bit in xor and in and
                        ok = false;
                    }
                    continue;
                }
                if(c & (1LL << j)){ //bit in xor
                    if(x + (1LL << j) <= a) x += (1LL << j); //i can set i set!
                    else y += (1LL << j);
                }
            }
            if(x != 0 && ok) cout << a-x << "\n";
            else cout << "-1\n";
        }else cout << "-1\n";
    }else cout << "-1\n";
}
