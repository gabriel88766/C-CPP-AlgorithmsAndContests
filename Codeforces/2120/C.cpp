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
        ll n, m;
        cin >> n >> m;
        ll mn = n;
        ll mx = (mn * (mn+1))/2;
        if(m >= mn && m <= mx){
            for(ll i=1;i<=n;i++){
                ll mn = (i * (i+1))/2; //for 1, 2, 3, ... i
                ll mx = mn + (n-i) * i;
                if(m <= mx){
                    assert(m - mn >= n-i);
                    cout << i << "\n";
                    for(int j=1;j<i;j++) cout << i << " " << j << "\n";
                    m -= mn;
                    for(int j=i+1;j<=n;j++){
                        ll nd = (n - j);
                        ll cur = min(i, m - nd);
                        cout << cur << " " << j << "\n";
                        m -= cur;
                    }
                    break;
                }
            }
        }else cout << "-1\n";
    }
}
