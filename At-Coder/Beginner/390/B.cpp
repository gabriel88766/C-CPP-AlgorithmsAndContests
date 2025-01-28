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
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    ll a = v[1], b = v[0];
    ll g = gcd(a, b);
    a /= g, b /= g;
    bool ok = true;
    for(int i=2;i<n;i++){
        ll ov = v[i-1];
        ov *= a;
        if(ov % b){
            ok = false;
            break;
        }
        ov /= b;
        if(ov != v[i]){
            ok = false;
            break;
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
