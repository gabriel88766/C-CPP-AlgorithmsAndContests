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
     int t;
    cin >> t;
    while(t--){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a % 2 == b % 2 && b % 2 == c % 2){
            if((a+b+c) % 3) cout << "-1\n";
            else{
                if(a > b) swap(a, b);
                if(b > c) swap(b, c);
                if(a > b) swap(a, b);
                ll d1 = (c-b), d2 = (c-a);
                if(d2/4 <= d1/2){
                    cout << (d1+d2)/6 << "\n";
                }else{
                    ll ans = d1/2;
                    a += ans*4;
                    ans += (c-a)/3;
                    cout << ans << "\n";
                }
            }
        }else cout << "-1\n";
    }
}
