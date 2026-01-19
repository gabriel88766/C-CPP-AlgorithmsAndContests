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
    ll g = 0;
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        while(a[i] != g){
            if((a[i] / g) % 2 == 0) a[i] /= 2;
            else if((a[i] / g) % 3 == 0) a[i] /= 3;
            else break;
            ans++;
        }
        if(a[i] != g){
            ans = -1;
            break;
        }
    }
    cout << ans << "\n";
}
