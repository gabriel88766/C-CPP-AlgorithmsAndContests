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
        int n;
        cin >> n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        ll g1 = 0, g2 = 0;
        for(int i=0;i<n;i+=2) g1 = gcd(g1, v[i]);
        for(int i=1;i<n;i+=2) g2 = gcd(g2, v[i]);
        bool ok1 = true, ok2 = true;
        for(int i=0;i<n;i+=2) if(!(v[i] % g2)) ok2 = false;
        for(int i=1;i<n;i+=2) if(!(v[i] % g1)) ok1 = false;
        if(ok1 || ok2){
            if(ok1) cout << g1 << "\n";
            else cout << g2 << "\n";
        }else cout << "0\n";
    }
}
